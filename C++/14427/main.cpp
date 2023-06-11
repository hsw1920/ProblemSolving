//
//  main.cpp
//  14427
//
//  Created by 홍승완 on 2023/06/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
vector<int>tree;

void setTree(int i){
    while(i){
        tree[i/2]=min(tree[i],tree[i/2]);
        i--;
    }
}

void changeVal(int idx, int e){
    tree[idx]=e;
    while(idx){
        if(idx%2==0){
            tree[idx/2]=min(tree[idx+1],tree[idx]);
        }
        else{
            tree[idx/2]=min(tree[idx-1],tree[idx]);
        }
        idx/=2;
    }
}
int findVal(int val, int startIdx){
    int idx=1;
    while(1){
        if(idx>=startIdx&&idx<startIdx+n){
            return idx-startIdx+1;
        }
        if(tree[idx*2]==val){
            idx*=2;
            continue;
        }
        idx=idx*2+1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    int h=ceil(log2(n));
    int treeSize=1<<(h+1);
    int startIdx=treeSize/2;
    tree.resize(treeSize+1);
    fill(tree.begin(),tree.end(),1e9);
    for(int i=startIdx;i<startIdx+n;i++){
        cin>>tree[i];
    }
    setTree(treeSize-1);
    cin>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            // b번째수를->c로 변경
            changeVal(startIdx+b-1,c);
        }
        else{
            // 수열에서 가장 크기가 작은 값의 인덱스를 출력
            // 트리 부모노드에 자식노드중 최솟값을 세팅
            // logN 으로 해당val을 find
            cout<<findVal(tree[1], startIdx)<<"\n";
        }
    }
    
    return 0;
}
