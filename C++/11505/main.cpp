//
//  main.cpp
//  11505
//
//  Created by 홍승완 on 2023/06/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD 1000000007
int n,m,k,a,b,c;
typedef long long ll;
vector<ll>tree;

void makeTree(int idx){
    while(idx){
        tree[idx/2]=tree[idx]*tree[idx/2]%MOD;
        idx--;
    }
}

ll calc(ll cur, ll a, ll b){
    return cur/a*b%MOD;
}
void update(int idx, int val){
    
    tree[idx]=val;
    while(idx){
        if(idx%2==0){
            tree[idx/2]=tree[idx]*tree[idx+1]%MOD;
        }else{
            tree[idx/2]=tree[idx]*tree[idx-1]%MOD;
        }
        idx/=2;
    }
}

ll getMulti(int s, int e){
    ll res=1;
    while(s<=e){
        if(s%2==1)res=res*tree[s++]%MOD;
        if(e%2==0)res=res*tree[e--]%MOD;
        s/=2;
        e/=2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>k;
    int h=ceil(log2(n));
    int treeSize=1<<(1+h);
    int startIdx=treeSize/2;
    tree.resize(treeSize-1);
    fill(tree.begin(),tree.end(),1);
    for(int i=startIdx;i<startIdx+n;i++){
        cin>>tree[i];
    }
    
    makeTree(treeSize-1);

    
    for(int i=0;i<m+k;i++){
        cin>>a>>b>>c;
        if(a==1){ // 변경
            update(startIdx+b-1,c);
        }else{ // 구간곱
            if(b>c)swap(b,c);
            cout<<getMulti(startIdx+b-1,startIdx+c-1)<<"\n";
        }
    }

    
    return 0;
}
