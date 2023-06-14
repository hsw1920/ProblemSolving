//
//  main.cpp
//  13537
//
//  Created by 홍승완 on 2023/06/13.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n,m,a,b,k;
vector<int>tree;

void makeTree(int idx){
    while(idx){
        tree[idx/2]=max(tree[idx/2],tree[idx]);
        idx--;
    }
}

int query(int cur, int s, int e, int k, int depth, int maxDepth){
    // cur의 자식들이 모두 (s,e)에 포함되면 리턴
    if(tree[cur]<k)return 0;
    if(tree[cur]>k){
        int st=cur*pow(2, maxDepth-depth);
        int ed=st+pow(2, maxDepth-depth)-1;
        if(st<s&&ed<s||st>e)
            return 0;
        if(st<=s&&ed<=e)
            return ed-s+1;
        if(st<=s&&ed>e)
            return e-s+1;
        
        if(st>=s&&ed<=e)
            return ed-st+1;
        if(st>=s&&ed>e)
            return e-st+1;
        
        return 0;
    }
    
    if(depth==maxDepth){
        if(cur>=s&&cur<=e){
            return 1;
        }
        return 0;
    }
    int left=query(cur*2,s,e,k,depth+1,maxDepth);
    int right=query(cur*2+1,s,e,k,depth+1,maxDepth);
    
    return left+right;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    int h=ceil(log2(n));
    int treeSize=1<<(1+h);
    int startIdx=treeSize/2;
    tree.resize(treeSize);
    fill(tree.begin(),tree.end(),0);
    for(int i=startIdx;i<startIdx+n;i++){
        cin>>tree[i];
    }
    // 구간최댓값을 부모에 저장
    makeTree(treeSize-1);
    
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>k;
        int st=startIdx+a-1;
        int ed=startIdx+b-1;
        cout<<query(1,st,ed,k,1,log2(startIdx)+1)<<"\n";
    }
    
//               1       log2(cur)+1 = depth
//        2            3
//     4     5      6     7
//    8 9  10 11  12 13 14 15  // log2(startIdx)+1 = depth
    
    // 2^(depth)의 차이는 트리의 개수
//    for(int i=1;i<treeSize;i++){
//        cout<<tree[i]<<" ";
//    }
    
    return 0;
}
