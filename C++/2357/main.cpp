//
//  main.cpp
//  2357
//
//  Created by 홍승완 on 2023/04/10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n,m,a,b,arr[100001];
ll tree1[100001], tree2[100001],tree3[100001], tree4[100001];
 
void updateMin1(ll i, ll val){
    while(i<=n){
        tree1[i]=min(tree1[i],val);
        i+=(i&-i);
    }
}

void updateMin2(ll i, ll val){
    while(i>0){
        tree2[i]=min(tree2[i],val);
        i-=(i&-i);
    }
}

void updateMax1(ll i, ll val){
    while(i<=n){
        tree3[i]=max(tree3[i],val);
        i+=(i&-i);
    }
}

void updateMax2(ll i, ll val){
    while(i>0){
        tree4[i]=max(tree4[i],val);
        i-=(i&-i);
    }
}

int minValue(ll a, ll b){
    ll v = 1e9;
    ll prev = a;
    ll curr = prev + (prev&-prev);
    while(curr<=b){
        v=min(v,tree2[prev]);
        prev=curr;
        curr=prev+(prev&-prev);
    }
    v=min(v,arr[prev]);
    prev = b;
    curr = prev - (prev&-prev);
    while(curr>=a){
        v=min(v,tree1[prev]);
        prev=curr;
        curr=prev-(prev&-prev);
    }
    return v;
}

int maxValue(ll a, ll b){
    ll v = 0;
    ll prev = a;
    ll curr = prev + (prev&-prev);
    while(curr<=b){
        v=max(v,tree4[prev]);
        prev=curr;
        curr=prev+(prev&-prev);
    }
    v=max(v,arr[prev]);
    prev = b;
    curr = prev - (prev&-prev);
    while(curr>=a){
        v=max(v,tree3[prev]);
        prev=curr;
        curr=prev-(prev&-prev);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    fill(tree1, tree1+n+1, 1e9);
    fill(tree2, tree2+n+1, 1e9);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        updateMin1(i, arr[i]);
        updateMin2(i, arr[i]);
        updateMax1(i, arr[i]);
        updateMax2(i, arr[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        cout<<minValue(a, b)<<" "<<maxValue(a, b)<<"\n";
    }
    return 0;
}
