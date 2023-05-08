//
//  main.cpp
//  2211
//
//  Created by 홍승완 on 2023/05/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pint;

int n,m,a,b,c,k,dist[1001];
priority_queue<pint,vector<pint>,greater<pint>>pq;
int parent[1001];
vector<pint>edge[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<=n;i++)dist[i]=1e9;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edge[a].push_back({c,b});
        edge[b].push_back({c,a});
    }
    dist[1]=0;
    pq.push({0,1});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                parent[nxt]=cur;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    cout<<n-1<<"\n";
    for(int i=2;i<=n;i++){
        cout<<parent[i]<<" "<<i<<"\n";
    }
    return 0;
}
