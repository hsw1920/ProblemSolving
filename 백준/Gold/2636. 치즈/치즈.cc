//
//  main.cpp
//  2636
//
//  Created by 홍승완 on 2024/01/14.
//

#include <bits/stdc++.h>
using namespace std;
int maps[102][102],visited[102][102];
int n,m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>maps[i][j];
            if(maps[i][j]==1){
                visited[i][j]=1;
            }
        }
    }
    int ret=0;
    int time=0;
    while(1){
        int res=0;
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                visited[i][j]=0;
                if(i==0||j==0||i==n+1||j==m+1)continue;
                if(maps[i][j]==1)res++;
            }
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0]=1;
        while(q.size()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx<0||yy<0||xx>n+1||yy>m+1||visited[xx][yy]==1){
                    continue;
                }
                visited[xx][yy]=1;
                if(maps[xx][yy]==1){
                    maps[xx][yy]=0;
                }else if(maps[xx][yy]==0){
                    q.push({xx,yy});
                }
                
            }
        }
        if(res==0){
            break;
        }else{
            time++;
            ret=res;
        }
    }
    cout<<time<<"\n";
    cout<<ret<<"\n";
    
    return 0;
}
