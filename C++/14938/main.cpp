//
//  main.cpp
//  14938
//
//  Created by 홍승완 on 2023/01/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int item[101];
    int maps[101][101];
    int n,m,r,a,b,c;
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        cin>>item[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            maps[i][j]=1e9;
            if(i==j)maps[i][j]=0;
        }
    }
    for(int i=1;i<=r;i++){
        cin>>a>>b>>c;
        maps[a][b]=min(maps[a][b],c);
        maps[b][a]=min(maps[b][a],c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                maps[i][j]=min(maps[i][j],maps[i][k]+maps[k][j]);
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=1;j<=n;j++){
            if(maps[i][j]<=m) res+=item[j];
        }
        ans=max(res,ans);
    }
    cout<<ans<<"\n";
    return 0;
}
