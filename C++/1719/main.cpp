//
//  main.cpp
//  1719
//
//  Created by 홍승완 on 2022/12/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>>maps[201];
int dist[201][201];
int res[201][201];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
typedef pair<int,int> pint;

int n,m,a,b,d;

void dijkstra(int k){
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    for(int i=1;i<=n;i++)
        dist[k][i]=res[k][i]=1e9;
    dist[k][k]=res[k][k]=0;
    pq.push({0,k});
    while(pq.size()){
        int dis=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        for(int i=0;i<maps[cur].size();i++){
            int next=maps[cur][i].first;
            int ndis=maps[cur][i].second;
            if(dist[k][next]>dist[k][cur]+ndis) {
                dist[k][next]=dist[k][cur]+ndis;
                if(res[k][cur]==0)res[k][next]=next;
                else res[k][next]=res[k][cur];
                pq.push({dist[k][next],next});
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>d;
        maps[a].push_back({b,d});
        maps[b].push_back({a,d});
    }
    for(int i=1;i<=n;i++)dijkstra(i);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)cout<<"-"<<" ";
            else cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

