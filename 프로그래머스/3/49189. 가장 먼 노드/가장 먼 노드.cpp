#include <bits/stdc++.h>

using namespace std;

int dist[20001];
vector<int>e[20001];
typedef pair<int,int> pint;

void dstra() {
    dist[1]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,1});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        
        if(dist[cur]<curd)continue;
        
        for(int i=0;i<e[cur].size();i++){
            int nxt = e[cur][i];
            int nxtd = 1;
            
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                pq.push({dist[nxt],nxt});
            }
        }
    }
}



int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    // 1번으로부터 가장 먼 곳의 개수. -> 다익으로 최단거리 모두 구하고 N완탐 2번
    for(auto k:edge){
        int from = k[0];
        int to = k[1];
        e[from].push_back(to);
        e[to].push_back(from);
    }
    
    for(int i=1;i<=n;i++)dist[i]=1e9;
    
    dstra();
    
    int mx=0;
    for(int i=2;i<=n;i++){
        mx=max(mx,dist[i]);
    }
    for(int i=2;i<=n;i++){
        if(dist[i]==mx) {
            answer++;
        }
    }
    
    return answer;
}