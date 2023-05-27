//
//  main.cpp
//  13308
//
//  Created by 홍승완 on 2023/05/27.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
ll n,m,u,v,w;
ll dist[2501];
ll pay[2501];
vector<pll>edge[2501];
vector<pll>resEdge[2501];

void dijkstra(ll s){
    dist[s]=0;
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    pq.push({dist[s],s});
    while(pq.size()){
        ll cur=pq.top().second;
        ll curd=pq.top().first;
        pq.pop();
        if(dist[cur]<curd)continue;
        for(ll i=0;i<edge[cur].size();i++){
            ll nxt=edge[cur][i].second;
            ll nxtd=edge[cur][i].first*pay[s];
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    for(ll i=1;i<=n;i++){
        if(i==s)continue;
        resEdge[s].push_back({dist[i],i});
    }
}

void resDijkstra(ll s){
    dist[s]=0;
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    pq.push({dist[s],s});
    while(pq.size()){
        ll cur=pq.top().second;
        ll curd=pq.top().first;
        pq.pop();
        if(dist[cur]<curd)continue;
        for(ll i=0;i<resEdge[cur].size();i++){
            ll nxt=resEdge[cur][i].second;
            ll nxtd=resEdge[cur][i].first;
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                pq.push({dist[nxt],nxt});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>pay[i];
    }
    for(ll i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    // 각 노드에서 모든 노드까지의 최단거리를 edge를 만들고
    // 해당 edge를 통해 다시 dijkstra를 실행
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=n;j++){dist[j]=1e12;}
        dijkstra(i);
    }
    for(ll i=0;i<=n;i++){dist[i]=1e12;}
    resDijkstra(1);

    cout<<dist[n]<<"\n";
    return 0;
}
