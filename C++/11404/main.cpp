//
//  main.cpp
//  11404
//
//  Created by 홍승완 on 2023/01/01.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n,m,a,b,c;
    int maps[101][101];
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            maps[i][j]=1e9;
            if(i==j)maps[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        maps[a][b]=min(maps[a][b],c);
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(maps[j][k]>maps[j][i]+maps[i][k]){
                    maps[j][k]=maps[j][i]+maps[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(maps[i][j]==1e9)cout<<"0 ";
            else cout<<maps[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
