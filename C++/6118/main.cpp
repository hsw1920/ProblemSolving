//
//  main.cpp
//  6118
//
//  Created by 홍승완 on 2023/06/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,u,v;
vector<int>edge[20001];
int dist[20001];
typedef pair<int,int> pint;
void dijkstra(){
    dist[1]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({0,1});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i];
            int nxtd=1;
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

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=0;i<=n;i++)dist[i]=1e9;
    dijkstra();
    
    // 숨을 헛간번호, 거리, 같은거리의 헛간 개수
    int ans1,ans2=0,ans3=0;
    
    for(int i=2;i<=n;i++){
        if(dist[i]>ans2){
            ans1=i;
            ans2=dist[i];
        }
    }
    for(int i=2;i<=n;i++){
        if(ans2==dist[i])ans3++;
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<"\n";
    
    return 0;
}
