//
//  main.cpp
//  14438
//
//  Created by 홍승완 on 2023/06/14.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,a,b,c;
vector<int>tree;

void makeTree(int idx){
    while(idx){
        tree[idx/2]=min(tree[idx/2],tree[idx]);
        idx--;
    }
}

void update(int idx, int val){
    tree[idx]=val;
    while(idx){
        if(idx%2==0){
            tree[idx/2]=min(tree[idx+1],tree[idx]);
        }else{
            tree[idx/2]=min(tree[idx-1],tree[idx]);
        }
        idx/=2;
    }
}

int query(int s, int e){
    int target=2e9;
    while(s<=e){
        if(s%2==1)target=min(target,tree[s++]);
        if(e%2==0)target=min(target,tree[e--]);
        s/=2;
        e/=2;
    }
    return target;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    int h=ceil(log2(n));
    int treeSize=1<<(1+h);
    int startIdx = treeSize/2;
    tree.resize(treeSize+1);
    fill(tree.begin(),tree.end(),1e9);
    for(int i=startIdx;i<startIdx+n;i++){
        cin>>tree[i];
    }
    makeTree(treeSize-1);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(a==1){
            update(startIdx+b-1,c);
        }else if(a==2){
            cout<<query(startIdx+b-1,startIdx+c-1)<<"\n";
        }
    }
    
    return 0;
}
