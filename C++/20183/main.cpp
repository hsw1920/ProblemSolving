//
//  main.cpp
//  20183
//
//  Created by 홍승완 on 2023/06/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
ll n,m,a,b,c,u,v,w;
vector<pll>edge[100001];
ll maxi[100001];
int visited[100001];

void dstra(){
    fill(maxi,maxi+100001,1e18);
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>>pq;
    pq.push({0,{0,a}});
    while(pq.size()){
        ll cur=pq.top().second.second;
        ll curm=pq.top().first;
        ll curd=pq.top().second.first;
        pq.pop();
        visited[cur]=1;
        for(ll i=0;i<edge[cur].size();i++){
            ll nxt=edge[cur][i].second;
            ll nxtd=edge[cur][i].first;
            ll nxtm=max(curm,nxtd);
            if(!visited[nxt] && curd+nxtd<=c && maxi[nxt]>nxtm){
                maxi[nxt]=nxtm;
                pq.push({nxtm,{curd+nxtd,nxt}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>a>>b>>c;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    dstra();
    if(maxi[b]==1e18)cout<<-1<<"\n";
    else cout<<maxi[b]<<"\n";
    
    return 0;
}
