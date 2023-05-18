//
//  main.cpp
//  2307
//
//  Created by 홍승완 on 2023/05/15.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int n,m,u,v,w;
vector<pint>edge[1001];
vector<pint>set;
int dist[1001];
int mindist=0;
void dstra(){
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,1});
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
                set.push_back({cur,nxt});
            }
        }
    }
}

void dstra2(int x, int y){
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,1});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        if(dist[cur]<curd)continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            if(cur==x&&nxt==y)continue;
            if(cur==y&&nxt==x)continue;
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
    for(int i=1;i<=n;i++)dist[i]=1e9;
    
    // 최소시간 구하기 -> dijkstra
    // 해당 지나는 구간들을 저장해놓기
    // 저장해둔 최단경로의 도로를 막고 그만큼
    // -> dijksta를 다시
    dist[1]=0;
    dstra();
    
    if(dist[n]==1e9){
        cout<<0<<"\n";
        return 0;
    }
    mindist=dist[n];
    int maxdist=0;
    for(int i=0;i<set.size();i++){
        int x=set[i].first;
        int y=set[i].second;
        for(int i=1;i<=n;i++)dist[i]=1e9;
        dist[1]=0;
        dstra2(x,y);
        if(dist[n]==1e9){
            cout<<-1<<"\n";
            return 0;
        }
        maxdist=max(maxdist,dist[n]);
    }
    cout<<maxdist-mindist<<"\n";
    
    
    
    return 0;
}
