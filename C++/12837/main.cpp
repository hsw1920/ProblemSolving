//
//  main.cpp
//  12837
//
//  Created by 홍승완 on 2023/06/16.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,a,b,c;
vector<long long>tree;

void update(int cur, int s, int e, int idx, int val){
    if(idx<s||idx>e)return;
    if(s==e){
        tree[cur]+=val;
        return;
    }
    update(cur*2,s,(s+e)/2,idx,val);
    update(cur*2+1,(s+e)/2+1,e,idx,val);
    tree[cur]=tree[cur*2]+tree[cur*2+1];
}

long long query(int cur, int s, int e, int qs, int qe){
    if(s>qe||e<qs)return 0;
    if(s>=qs&&e<=qe) return tree[cur];
    int mid=(s+e)/2;
    long long left=query(cur*2, s, mid, qs, qe);
    long long right=query(cur*2+1, mid+1, e, qs, qe);
    return left+right;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    int h=ceil(log2(n));
    int treeSize=1<<(1+h);
    tree.resize(treeSize);
    
    while(m--){
        cin>>a>>b>>c;
        if(a==1){
            update(1,0,n-1,b-1,c);
        }else{
            cout<<query(1,0,n-1,b-1,c-1)<<"\n";
        }
    }
    
    return 0;
}
