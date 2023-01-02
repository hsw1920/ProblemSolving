//
//  main.cpp
//  18223
//
//  Created by 홍승완 on 2023/01/02.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int,int> pint;
stack<int>st;
vector<pint>maps[5001];
int dist[5001];
int v,e,p,a,b,c;


int dijkstra(int start, int end){
    
    //init
    for(int i=1;i<=v;i++)
        dist[i]=1e9;
    dist[start]=0;
    
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({start,0});
    
    while(pq.size()){
        int cur = pq.top().first;
        int cost =pq.top().second;
        pq.pop();
        for(int i=0;i<maps[cur].size();i++){
            int nxt = maps[cur][i].first;
            int nxtcost = maps[cur][i].second;
            if(dist[nxt]>dist[cur]+nxtcost){
                dist[nxt]=dist[cur]+nxtcost;
                pq.push({nxt,dist[nxt]});
            }
        }
    }
    
    return dist[end];
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>v>>e>>p;
    
    // 출발지는 1, 건우는 p에 있고 종점은 v
    // 최단경로가 p를 지나는가?
    
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        maps[a].push_back({b,c});
        maps[b].push_back({a,c});
    }
    
    if(dijkstra(1,v)>=dijkstra(1,p)+dijkstra(p,v))cout<<"SAVE HIM\n";
    else cout<<"GOOD BYE\n";
    
    return 0;
}
