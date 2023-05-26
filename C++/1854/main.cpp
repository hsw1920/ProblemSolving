//
//  main.cpp
//  1854
//
//  Created by 홍승완 on 2023/05/26.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
ll n,m,k,u,v,w; // 단방향
vector<pll>edge[1001];

void dstra(ll s){
    priority_queue<ll>res[1001];
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    res[s].push(0);
    pq.push({0,s});
    while(pq.size()){
        ll cur=pq.top().second;
        ll curd=pq.top().first;
        pq.pop();
        for(ll i=0;i<edge[cur].size();i++){
            ll nxt=edge[cur][i].second;
            ll nxtd=edge[cur][i].first;
            
            if(res[nxt].size()<k){
                res[nxt].push(curd+nxtd);
                pq.push({curd+nxtd,nxt});
            }
            else if(res[nxt].top()>curd+nxtd){
                res[nxt].pop();
                res[nxt].push(curd+nxtd);
                pq.push({curd+nxtd,nxt});
            }
        }
    }
    for(ll i=1;i<=n;i++){
        if(res[i].size()<k){
            cout<<-1<<"\n";
        }else {
            cout<<res[i].top()<<"\n";
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>k;
    
    for(ll i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
    }
    
    dstra(1);
    
    return 0;
}
