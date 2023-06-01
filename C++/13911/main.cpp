//
//  main.cpp
//  13911
//
//  Created by 홍승완 on 2023/05/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int V,E,u,v,w,M,x,S,y;
vector<pint>edge[10001];

bool mac[10001];
bool star[10001];
pint res[10001]; // 0이 아닌것만 답으로
priority_queue<pint,vector<pint>,greater<pint>>pq;
void dstra(int state){
    int dist[10001];
    fill(dist+1,dist+V+1,1e9);
    for(int i=1;i<=V;i++){
        if(mac[i]==1&&state==0){
            dist[i]=0;
            pq.push({dist[i],i});
        }
    
        else if(star[i]==1&&state==1){
            dist[i]=0;
            pq.push({dist[i],i});
        }
    }
    
    
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        if(dist[cur]<curd)continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(dist[i]<=x&&state==0&&dist[i]!=0&&star[i]==0&&mac[i]!=1){
            if(res[i].first==0)res[i].first=dist[i];
            else {
                res[i].first=min(res[i].first,dist[i]);
            }
            
        }
        else if(dist[i]<=y&&state==1&&dist[i]!=0&&mac[i]==0&&star[i]!=1){
            if(res[i].second==0)res[i].second=dist[i];
            else {
                res[i].second=min(res[i].second,dist[i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>V>>E;
    
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    cin>>M>>x;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        mac[tmp]=1; // 맥도날드 정점
        // -> 맥날정점에서 dijkstra 해서 가능한 집 -> res[i].first
        
    }
    cin>>S>>y;
    for(int i=0;i<S;i++){
        int tmp;
        cin>>tmp;
        star[tmp]=1; // 스벅 정점
        // -> 스벅정점에서 dijkstra 해서 가능한 집 -> res[i].second
    }
    dstra(0);
    dstra(1);
    
    int answer=1e9;
    for(int i=1;i<=V;i++){
        if(res[i].first<=x&&res[i].second<=y&&res[i].first!=0&&res[i].second!=0){
            if(mac[i]!=1&&star[i]!=1) // 해당정점이 맥날,스벅이 아니어야함
                answer=min(answer,res[i].first+res[i].second);
        }
    }
    if(answer!=1e9)
        cout<<answer<<"\n";
    else {
        cout<<-1<<"\n";
    }
    
    return 0;
}
