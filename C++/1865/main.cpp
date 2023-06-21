//
//  main.cpp
//  1865
//
//  Created by 홍승완 on 2023/06/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define init cin.tie(0)->ios_base::sync_with_stdio(0)

using namespace std;

typedef pair<int,int> pint;
int TC,n,m,w,S,E,T;

vector<pint>edge[501];
int dist[501];

int main() {
    init;
    cin>>TC;
    while(TC--){
        cin>>n>>m>>w;
        
        //init
        fill(dist,dist+n+1,1e9);
        dist[1]=0;
        for(int i=0;i<=n;i++)edge[i].clear();
        
        // 도로, 양방향
        for(int i=0;i<m;i++){
            cin>>S>>E>>T; // u,v,이동시간
            edge[S].push_back({T,E});
            edge[E].push_back({T,S});
        }
        
        // 웜홀, 단방향
        for(int i=0;i<w;i++){
            cin>>S>>E>>T; // u,v,줄어드는시간
            edge[S].push_back({-T,E});
        }
        
        bool chk=false;
        for(int i=1;i<=n;i++){
            for(int u=1;u<=n;u++){
                for(int k=0;k<edge[u].size();k++){
                    int v=edge[u][k].second;
                    int w=edge[u][k].first;
                    if(dist[v]>dist[u]+w){
                        dist[v]=dist[u]+w;
                        if(i==n)chk=true;
                    }
                }
            }
        }

        if(chk)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
