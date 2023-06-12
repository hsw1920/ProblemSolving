//
//  main.cpp
//  2268
//
//  Created by 홍승완 on 2023/06/12.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n,m,a,b,c;
vector<ll>tree;

ll getSum(int s, int e){
    ll sum=0;
    while(s<=e){
        if(s%2==1)sum+=tree[s++];
        if(e%2==0)sum+=tree[e--];
        s/=2;
        e/=2;
    }
    return sum;
}

void update(int idx, ll val){
    ll diff=val-tree[idx];
    tree[idx]+=diff;
    
    while(idx){
        tree[idx/2]+=diff;
        idx/=2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    int h=ceil(log2(n));
    int treeSize=1<<(1+h);
    int startIdx=treeSize/2;
    tree.resize(treeSize+1);
    
    for(int i=0;i<m;i++){
        // 0일때 sum
        // 1일때 modify
        cin>>a>>b>>c;
        if(a==0){
            if(b>c)swap(b,c);
            cout<<getSum(startIdx+b-1,startIdx+c-1)<<"\n";
        }else if(a==1){
            update(startIdx+b-1,c);
        }
    }
    
    return 0;
}
