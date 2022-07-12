//
//  main.cpp
//  2636
//
//  Created by 홍승완 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int cnt=0;
int n,m,k=0;
int maps[101][101];
int visited[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int t=1;
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
}
void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    while (q.size()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&visited[xx][yy]==0){
                //가장자리 치즈일 때
                if(maps[xx][yy]==1){
                    visited[xx][yy]=1;
                    maps[xx][yy]=0;
                    cnt++;
                }
                //치즈 아닐 때
                else{
                    visited[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
        }
    }
    while(1){
        init();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1) &&visited[i][j]==0) bfs(i,j);
                else if((j==0||j==m-1) &&visited[i][j]==0) bfs(i,j);
            }
        }
        int tmp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maps[i][j]==1)tmp++;
            }
        }
        if(tmp==0){
            cout<<t<<"\n"<<cnt;
            break;
        }
        else{
            t++;
            cnt=0;
        }
    }
    
    return 0;
}
