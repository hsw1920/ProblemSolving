//
//  main.cpp
//  13424
//
//  Created by 홍승완 on 2023/05/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// n개의 방, m개의 양방향통로
// 친구 k명
// n개의 방중 한곳을 정하여 모임장소로 이용
// 각 친구들은 장소로 이동 (이때도 최단거리로)
// -> 친구들의 이동거리의 총합이 최소가 되는 방을 모임장소로 (해당 방이 여러개라면 가장 번호가 작은 방)

typedef pair<int,int> pint;
int t,n,m,u,v,w,k,pos;
priority_queue<pint,vector<pint>,greater<pint>>pq;
vector<pint>edge[101];
int graph[101][101];
int dist[101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)graph[i][j]=0;
                else graph[i][j]=1e9;
            }
        }
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            graph[u][v]=w;
            graph[v][u]=w;
            edge[u].push_back({w,v});
            edge[v].push_back({w,u});
        }
        
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(graph[i][k]+graph[k][j]<graph[i][j]){
                        graph[i][j]=graph[i][k]+graph[k][j];
                    }
                }
            }
        }
        
        cin>>k;
        vector<int>pos(k);
        for(int i=0;i<k;i++){
            cin>>pos[i];
        }
        // 해당 dist들의 합의 최소가진 idx를 구하기
        // 다익스트라를 n번 돌려야함 or 플로이드와샬
        int res=1e9;
        int ans=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=0;
            for(int j=0;j<k;j++){
                sum+=graph[pos[j]][i];
            }
            if(sum<res){
                res=sum;
                ans=i;
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
