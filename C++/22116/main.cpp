//
//  main.cpp
//  22116
//
//  Created by 홍승완 on 2023/05/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int n;
int maps[1001][1001];
vector<pint>edge[1000001];
int dist[1000001];
int visited[1001000];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dijkstra(int x){
    dist[x]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({dist[x],x});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        
        // coordinate
        int xx=cur/n;
        int yy=cur%n;
        if(dist[cur]<curd)continue;
        for(int i=0;i<4;i++){
            int nx=xx+dx[i];
            int ny=yy+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<n){
                int nxt=nx*n+ny;
                int nxtd=maps[nx][ny];
                if(dist[nxt]>max(dist[cur],abs(nxtd-maps[xx][yy]))){
                    dist[nxt]=min(dist[nxt],max(dist[cur],abs(nxtd-maps[xx][yy])));
                    pq.push({dist[nxt],nxt});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
    for(int i=0;i<n*n;i++){
        dist[i]=1e9;
    }
    dijkstra(0);
    cout<<dist[n*n-1]<<"\n";
    
    return 0;
}
