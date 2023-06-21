//
//  main.cpp
//  1738
//
//  Created by 홍승완 on 2023/06/21.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

int n,m,u,v,w;
typedef pair<int,int> pint;
vector<pint>edge[101];
vector<pint>rev_edge[101];
int dist[101];
int prv[101];
int visited[101];
int main() {
    init
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back({-w,v});
        rev_edge[v].push_back({-w,u});
    }
    
    queue<int>q;
    q.push(n);
    visited[n]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int i=0;i<rev_edge[x].size();i++){
            int nxt=rev_edge[x][i].second;
            if(visited[nxt]==0){
                q.push(nxt);
                visited[nxt]=1;
            }
        }
    }
    
    // 시작1, 콘도n
    int cycle=false;
    fill(dist+2,dist+n+1,1e9);
    for(int i=1;i<=n;i++){
        for(int u=1;u<=n;u++){
            for(int k=0;k<edge[u].size();k++){
                int v=edge[u][k].second;
                int w=edge[u][k].first;
                if(dist[v]>dist[u]+w && dist[u]!=1e9){
                    dist[v]=dist[u]+w;
                    prv[v]=u;
                    if(i==n&&visited[v]==1)
                        cycle=true;
                }
            }
        }
    }

    
    if(cycle)cout<<-1<<"\n";
    else{
        vector<int>ans;
        ans.push_back(n);
        int cur=n;
        while(prv[cur]!=0){
            ans.push_back(prv[cur]);
            cur=prv[cur];
        }
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
    
}
