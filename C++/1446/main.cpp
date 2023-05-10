//
//  main.cpp
//  1446
//
//  Created by 홍승완 on 2023/05/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int n,d,u,v,w;
vector<pint>edge[10001];
int dist[10001];
void dstra(int x){
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({dist[x],x});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        dist[cur]=min(dist[cur],cur);
        pq.pop();
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            dist[nxt]=min(dist[nxt],dist[cur]+nxt-cur);
            if(dist[nxt]>=curd+nxtd){
                dist[nxt]=curd+nxtd;
                dist[d]=min(dist[nxt] + d-nxt,dist[d]);
                pq.push({dist[nxt],nxt});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>d;
    
    for(int i=0;i<n;i++){
        cin>>u>>v>>w;
        if(v<=d)
            edge[u].push_back({w,v}); // 단방향
    }
    for(int i=0;i<d;i++)
        edge[i].push_back({1,i+1});
    for(int i=0;i<=d;i++)dist[i]=i;
    dstra(0);
    cout<<dist[d]<<"\n";
    return 0;
}
