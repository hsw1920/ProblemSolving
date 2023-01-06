//
//  main.cpp
//  23286
//
//  Created by 홍승완 on 2023/01/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int maps[301][301];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n,m,t,u,v,s,e,h;
    cin>>n>>m>>t;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            maps[i][j]=1e9;
        }
    }
    
    for(int i=0;i<m;i++){
        cin>>u>>v>>h; // 단방향
        maps[u][v]=h;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(maps[i][j]>=maps[i][k] && maps[i][j]>=maps[k][j]){
                    maps[i][j]=max(maps[i][k],maps[k][j]);
                }
            }
        }
    }
    
    for(int i=0;i<t;i++){
        cin>>s>>e; // 출발,도착 , 가장 높은 허들 높이의 최솟값, 도착지점으로 못가면 -1
        if(maps[s][e]==1e9)cout<<-1<<"\n";
        else cout<<maps[s][e]<<"\n";
    }
    
    return 0;
}
