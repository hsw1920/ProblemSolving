//
//  main.cpp
//  24042
//
//  Created by 홍승완 on 2023/04/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

// 지역의 수 N
// 횡단보도 주기 M
// 파란불 -> 1분,
// target 1번 지역에서 N번 지역까지 가는데 필요한 최소시간

//
typedef long long ll;
typedef pair<ll,ll> pll;
ll n, m;
ll a,b;
ll dist[100001];
vector<vector<pair<ll,ll>>>edge(100001);

priority_queue<pll,vector<pll>,greater<pll>>pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fill(dist,dist+100001,1e18);
    
    // input
    cin>>n>>m;
    
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        edge[a].push_back({b,i});
        edge[b].push_back({a,i});
    }
    
    // dijkstra ㄱㄱ
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        ll nowd = pq.top().first;
        ll now = pq.top().second;
        pq.pop();
        if (dist[now] != nowd)continue;
        for(auto k: edge[now]){
            ll nxt = k.first;
            ll nxtd = k.second;
            if(nxtd < nowd){
                ll tmp = (nowd-nxtd)/m;
                if((nowd-nxtd)%m!=0) tmp++;
                nxtd += m*tmp;
            }
            if(dist[nxt]>nxtd){
                dist[nxt]=nxtd;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    cout<<dist[n];
    
    return 0;
}
