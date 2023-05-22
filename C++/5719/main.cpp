//
//  main.cpp
//  5719
//
//  Created by 홍승완 on 2023/05/22.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pint;
int n,m,s,d,u,v,w;
int dist[501];
vector<int> prv[501];
vector<pint>edge[501];

void dstra(int x){
    dist[x]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({dist[x],x});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        if(dist[x]<curd)continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                prv[nxt].clear();
                prv[nxt].push_back(cur);
                pq.push({dist[nxt],nxt});
            }
            else if(dist[nxt]==curd+nxtd){
                prv[nxt].push_back(cur);
            }
        }
    }
}

void bfs(){
    queue<int>q;
    q.push(d);
    int visited[501]={0,};
    visited[d]=1;
    while(q.size()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<prv[cur].size();i++){
            edge[prv[cur][i]][cur] = {1e9,edge[prv[cur][i]][cur].second};
            if(visited[prv[cur][i]]==0){
                q.push(prv[cur][i]);
                visited[prv[cur][i]]=1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    while(1){
        cin>>n>>m;
        if(n==0&&m==0)break;
        cin>>s>>d;
        for(int i=0;i<n;i++){
            dist[i]=1e9;
            prv[i].clear();
            edge[i].clear();
        }
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            edge[u].push_back({w,v});
        }
        dstra(0);
        bfs();
        for(int i=0;i<n;i++){
            dist[i]=1e9;
        }
        dstra(0);
        
        if(dist[n-1]==1e9){
            cout<<-1<<"\n";
        }else {
            cout<<dist[n-1]<<"\n";
        }
    }
    
    return 0;
}
