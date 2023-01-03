//
//  main.cpp
//  17835
//
//  Created by 홍승완 on 2023/01/03.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<long long,long long> pll;
vector<pll> maps[100001]; // {도시, 길이}
vector<long long> target;
long long dist[100001];
long long resNum, resDist;
long long n,m,k,u,v,c;

priority_queue<pll,vector<pll>,greater<pll>>pq;

void dijkstra(){
    
    while(pq.size()){
        int cur = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();
        
        // ###1 이거 안해주면 시간초과남..
        if(dist[cur]<cost)continue;
        
        for(int i=0;i<maps[cur].size();i++){
            int nxt = maps[cur][i].second;
            long long nxtcost = maps[cur][i].first;
            if(dist[nxt]>cost+nxtcost){
                dist[nxt]=cost+nxtcost;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    

    // 가장 먼 도시
    for(int i=1;i<=n;i++){
        if(resDist<dist[i]){
            resDist=dist[i];
            resNum=i;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    // n개 도시 k면접장 배치, 단방향, edge 여러개가능, 최단거리 -> 다익스트라
    // m개의 edge 도시번호 uv, 길이c

    cin>>n>>m>>k;
    
    for(int i=0;i<m;i++){
        cin>>u>>v>>c; // u에서 v로 길이c, 단방향
        maps[v].push_back({c,u}); // 역그래프로 생성
    }
    
    // dist 초기화
    // ###2 long long이라 MAX값 1e9보다 커야함
    for(int i=1;i<=n;i++)dist[i]=1e17;
    // 면접장 도시
    for(int i=0;i<k;i++){
        long long tmp;
        cin>>tmp;
        dist[tmp]=0; pq.push({0,tmp});
    }

    resNum=resDist=0;
    dijkstra();
    
    // dijkstra의 시작점은 여러개여도 됨
    // 어떤 시작점에서 출발했는지 알 수 없지만 임의의 노드까지 가장 짧은 거리를 dist에 저장할 수 있음
    cout<<resNum<<"\n"<<resDist<<"\n";
    return 0;
}
