//
//  main.cpp
//  2325
//
//  Created by 홍승완 on 2023/05/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int n,m,u,v,w;
vector<pint>edge[1001];
int dist[1001];
int dist2[1001];
int prevd[1001];
int maxDist=0;
int xx,yy;

void dstra(int x){
    dist[x]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,x});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        if(curd>dist[cur])continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                pq.push({dist[nxt],nxt});
                prevd[nxt]=cur;
            }
        }
    }
}

void dstra2(int x){
    int cnt=0;
    dist2[x]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,x});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        if(curd>dist2[cur])continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            
            if((cur==xx && nxt==yy)||(cur==yy && nxt==xx)){
                continue;
            }
            if(dist2[nxt]>curd+nxtd){
                dist2[nxt]=curd+nxtd;
                pq.push({dist2[nxt],nxt});
            }
        }
    }
    maxDist=max(maxDist,dist2[n]);
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
    for(int i=0;i<=n;i++)dist[i]=1e9;
    dstra(1);
    for(int i=1;i<=n;i++){
        xx=prevd[i];
        yy=i;

        for(int i=0;i<=n;i++)
            dist2[i]=1e9;
        dstra2(1);
    }
    
    cout<<maxDist<<"\n";
    
    return 0;
}
