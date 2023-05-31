//
//  main.cpp
//  1162
//
//  Created by 홍승완 on 2023/05/30.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pint;
int n,m,k,u,v;
long long w;
vector<pint>edge[10001];
long long dist[10001][21];

void dstra(){
    priority_queue<pair<long long,pint>,vector<pair<long long,pint>>,greater<pair<long long,pint>>>pq;
    dist[1][0]=0; // node, k
    pq.push({0,{0,1}});
    while(pq.size()){
        int cur=pq.top().second.second;
        long long curd=pq.top().first;
        int curk=pq.top().second.first;
        pq.pop();
        if(dist[cur][curk]<curd)continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            long long nxtd=edge[cur][i].first;
            if(curk>k)continue;
            if(dist[nxt][curk]>curd+nxtd){
                dist[nxt][curk]=curd+nxtd;
                pq.push({dist[nxt][curk],{curk,nxt}});
            }
            for(int j=curk+1;j<=k;j++){
                if(dist[nxt][j]>curd){
                    dist[nxt][j]=curd;
                    pq.push({dist[nxt][j],{j,nxt}});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    // k개 이하의 도로를 포장함
    
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dist[i][j]=1e12;
        }
    }
    dstra();
    long long res=1e12;
    for(int i=0;i<=k;i++){
        res=min(res,dist[n][i]);
    }
    cout<<res<<"\n";
    
    return 0;
}
