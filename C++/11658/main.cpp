//
//  main.cpp
//  11658
//
//  Created by 홍승완 on 2023/04/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll arr[1025][1025];
ll tree[1025][1025];
ll n,m,w,x,y,c,x1,y1,x2,y2;

void update(ll x, ll y, ll val){
    while(x<=n){
        ll yy = y;
        while(yy<=n){
            tree[x][yy]+=val;
            yy+=(yy&-yy);
        }
        x+=(x&-x);
    }
}

ll sum(ll x, ll y){
    ll res = 0;
    while(x>0){
        ll yy=y;
        while(yy>0){
            res+=tree[x][yy];
            yy-=(yy&-yy);
        }
        x-=(x&-x);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>arr[i][j];
            update(i,j,arr[i][j]);
        }
    }
    for(ll i=0;i<m;i++){
        cin>>w;
        if(w==0){
            cin>>x>>y>>c;
            ll diff=c-arr[x][y];
            arr[x][y]=c;
            update(x, y, diff);
        }else {
            cin>>x1>>y1>>x2>>y2;
            cout<<sum(x2,y2)-sum(x2,y1-1) - (sum(x1-1,y2)-sum(x1-1,y1-1))<<"\n";
        }
    }
    return 0;
}
