//
//  main.cpp
//  16118
//
//  Created by 홍승완 on 2023/05/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


typedef pair<int,int> pint;
int n,m,u,v,w;
vector<pint>edge[4001];
int fdist[4001];
int wdist[4001][2];
void Fdstra(){
    fdist[1]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,1});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        if(fdist[cur]<curd)continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            if(fdist[nxt]>curd+nxtd){
                fdist[nxt]=curd+nxtd;
                pq.push({fdist[nxt],nxt});
            }
        }
    }
}
void Wdstra(){
    wdist[1][0]=0;
    priority_queue<pair<int,pint>,vector<pair<int,pint>>,greater<pair<int,pint>>>pq;
    pq.push({0,{1,0}}); // 거리, 노드, state
    while(pq.size()){
        int cur=pq.top().second.first;
        int state=pq.top().second.second;
        int curd=pq.top().first;
        pq.pop();
        if(wdist[cur][state]<curd)continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            if(state==0){
                if(wdist[nxt][1]>curd+nxtd/2){
                    wdist[nxt][1]=curd+nxtd/2;
                    pq.push({wdist[nxt][1],{nxt,1}});
                }
            }
            else {
                if(wdist[nxt][0]>curd+nxtd*2){
                    wdist[nxt][0]=curd+nxtd*2;
                    pq.push({wdist[nxt][0],{nxt,0}});
                }
            }
            
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w*2,v});
        edge[v].push_back({w*2,u});
    }

    for(int i=1;i<=n;i++){
        fdist[i]=1e9;
        wdist[i][0]=1e9;
        wdist[i][1]=1e9;
    }
    Fdstra();
    Wdstra();
    int res=0;
    for(int i=1;i<=n;i++){
        if(fdist[i]<min(wdist[i][0],wdist[i][1])){
            res++;
        }
    }
    cout<<res<<"\n";
    return 0;
}
