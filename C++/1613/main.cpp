//
//  main.cpp
//  1613
//
//  Created by 홍승완 on 2023/06/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

int n,k,s; // 정점, 간선, 사건 쌍의 수
int u,v; // 사건 쌍 번호

int maps[401][401];

int main() {
    init
    
    cin>>n>>k;
    
    // init
    fill(&maps[0][0],&maps[n][n],1e9);
    
    //input
    for(int i=0;i<k;i++){
        cin>>u>>v;
        maps[u][v]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                maps[i][j]=min(maps[i][j],maps[i][k]+maps[k][j]);
    
    cin>>s;
    // input -> output -> 앞먼저 -1, 뒤 1, 모르면 0
    for(int i=0;i<s;i++){
        cin>>u>>v;
        if(maps[u][v]!=1e9)cout<<-1<<"\n";
        else if(maps[v][u]!=1e9)cout<<1<<"\n";
        else cout<<0<<"\n";
    }

    return 0;
}
