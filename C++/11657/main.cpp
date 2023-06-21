//
//  main.cpp
//  11657
//
//  Created by 홍승완 on 2023/06/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;
typedef pair<int,int> pint;

int n,m,a,b,c;
vector<pint>edge[501];
int dist[501];

int main() {
    init
    
    cin>>n>>m;
    
    fill(dist,dist+n+1,1e9);
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edge[a].push_back({c,b});
    }
    
    // 1번도시에서 출발
    dist[1]=0;
    
    // 벨만포드
    for(int i=0;i<n-1;i++){
        for(int u=1;u<=n;u++){
            for(int k=0;k<edge[u].size();k++){
                int v=edge[u][k].second;
                int w=edge[u][k].first;
                if(dist[u]==1e9)continue;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                }
            }
        }
    }
    
    // 음의 사이클 여부
    for(int u=1;u<=n;u++){
        for(int k=0;k<edge[u].size();k++){
            int v=edge[u][k].second;
            int w=edge[u][k].first;
            if(dist[u]==1e9)continue;
            if(dist[v]>dist[u]+w){
                cout<<-1<<"\n";
                return 0;
            }
        }
    }
    
    // output
    for(int i=2;i<=n;i++){
        if(dist[i]==1e9)
            cout<<-1<<"\n";
        else
            cout<<dist[i]<<"\n";
    }
    return 0;
}
