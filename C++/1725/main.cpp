//
//  main.cpp
//  1725
//
//  Created by 홍승완 on 2023/06/23.
//

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>

#define init cin.tie(0)->ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<int>tree;
vector<int>arr;

void initTree(int cur, int s, int e){
    if(s==e){
        tree[cur]=s;
        return;
    }
    int mid=(s+e)/2;
    initTree(cur*2, s, mid);
    initTree(cur*2+1, mid+1, e);
    if(arr[tree[cur*2]]<=arr[tree[cur*2+1]]){
        tree[cur]=tree[cur*2];
    }else{
        tree[cur]=tree[cur*2+1];
    }
}

int query(int cur, int s, int e, int qs, int qe){
    if(qs>e||s>qe)return -1;
    if(s>=qs&&e<=qe)return tree[cur];
    int mid =(s+e)/2;
    int l=query(cur*2, s, mid, qs, qe);
    int r=query(cur*2+1, mid+1, e, qs, qe);
    if(l==-1)return r;
    else if(r==-1)return l;
    else{
        if(arr[l]<=arr[r])return l;
        else return r;
    }
}

long long getRect(int s, int e){
    int idx=query(1, 0, n-1, s, e);
    long long res=(long long)(e-s+1)*(long long)(arr[idx]);
    if(idx+1<=e){
        long long tmp = getRect(idx+1, e);
        res=max(res,tmp);
    }
    if(idx-1>=s){
        long long tmp = getRect(s, idx-1);
        res=max(res,tmp);
    }
    return res;
}


int main() {
    init;
    cin>>n;
    int h=ceil(log2(n));
    int treeSize=1<<(1+h);
    tree.resize(treeSize);
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    initTree(1,0,n-1);
    cout<<getRect(0,n-1)<<"\n";
    
    return 0;
}
