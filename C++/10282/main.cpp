//
//  main.cpp
//  10282
//
//  Created by 홍승완 on 2023/05/23.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pint;
int t,n,d,c,u,v,w;
vector<pint>edge[10001];
int dist[10001];
int resN=0,resD=0;
void dstra(int x){
    dist[x]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({dist[x],x});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        if(dist[cur]>curd)continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
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
    
    cin>>t;
    while(t--){
        cin>>n>>d>>c;
        resN=resD=0;
        for(int i=0;i<=n;i++){
            edge[i].clear();
            dist[i]=1e9;
        }
        for(int i=0;i<d;i++){
            cin>>v>>u>>w; // 뒤에꺼부터 시작함
            edge[u].push_back({w,v});
        }
        dstra(c);
        for(int i=1;i<=n;i++){
            if(dist[i]!=1e9){
                resN++;
                resD=max(resD,dist[i]);
            }
        }
        cout<<resN<<" "<<resD<<"\n";
    }
    
    return 0;
}
