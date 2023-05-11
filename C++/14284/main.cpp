//
//  main.cpp
//  14284
//
//  Created by 홍승완 on 2023/05/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int n,m,u,v,w,s,t;
vector<pint>edge[5001];
int dist[5001];

void dstra(int s){
    dist[s]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,s});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
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
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    cin>>s>>t;
    for(int i=0;i<=n;i++)dist[i]=1e9;
    dstra(s);
    cout<<dist[t]<<"\n";
    return 0;
}
