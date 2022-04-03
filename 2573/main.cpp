//
//  main.cpp
//  2573
//
//  Created by 홍승완 on 2022/04/03.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
bool vis[301][301]={0,};
int map[301][301];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cnt=0;
void dfs(int x, int y){
    if(map[x][y]==0)
        return ;
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        //먼저 빙산 녹는것 진행
        //4방향에서 0일때 각각 -1씩
        if(vis[xx][yy]==0&&map[xx][yy]==0){
            if(map[x][y]>0)map[x][y]--;
        }
        //dfs
        if(vis[xx][yy]==0&&xx>0&&yy>0&xx<n&&yy<m
           &map[xx][yy]!=0){
            dfs(xx,yy);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    int time=0;
    while(1){
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]!=0&&!vis[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        if(cnt>1){
            cout<<time;
            break;
        }
        if(cnt==0){
            cout<<0;
            break;
        }
        time++;
    }
    return 0;
}
