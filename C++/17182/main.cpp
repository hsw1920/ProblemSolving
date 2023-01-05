//
//  main.cpp
//  17182
//
//  Created by 홍승완 on 2023/01/05.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int dist[1001];
int dists[1001][1001];
int visited[1001];
int maps[11][11];

int n,k,t;
int res=0;
int ans=1e9;
void dfs(int x, int d, int num){
    if(ans<d)return;
    if(num==n){
        ans=min(ans,d);
        return;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==1)continue;
        visited[i]=1;
        dfs(i,d+dists[x][i],num+1);
        visited[i]=0;
    }
    
}

void dijkstra(int start){
    for(int i=0;i<n;i++)dist[i]=1e9;
    dist[start]=0;
    priority_queue<pint,vector<pint>,greater<pint>> pq;
    pq.push({0,start});

    while(pq.size()){
        int curcost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur]<curcost)continue;
        for(int i=0;i<n;i++){
            int nxtcost = maps[cur][i];
            int nxt = i;
            
            if(dist[nxt]>dist[cur]+nxtcost) {
                dist[nxt]=dist[cur]+nxtcost;
                pq.push({dist[nxt],nxt});
                
            }
        }
    }
    for(int i=0;i<n;i++){
        dists[start][i]=dist[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
    for(int i=0;i<n;i++){
        dijkstra(i);
    }
    
    
    visited[k]=1;
    dfs(k,0,1);
    
    cout<<ans<<"\n";
    
    return 0;
}
