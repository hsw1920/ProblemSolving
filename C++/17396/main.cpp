//
//  main.cpp
//  17396
//
//  Created by 홍승완 on 2023/05/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<long long,int> pint;
int n,m,u,v;
long long w;
vector<pint>edge[100001];
long long dist[100001];
int visible[100001];

void dstra(int x){
    dist[x]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,x});
    while(pq.size()){
        int cur=pq.top().second;
        long long curd=pq.top().first;
        pq.pop();
        if(visible[cur]==1)continue;
        if(curd>dist[cur])continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            long long nxtd=edge[cur][i].first;
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
    for(int i=0;i<n;i++){
        cin>>visible[i];
    }
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    for(int i=0;i<n;i++)dist[i]=9e12;
    
    dstra(0);
    
    if(dist[n-1]==9e12){
        cout<<-1<<"\n";
    } else {
        cout<<dist[n-1];
    }
    
    
    return 0;
}
