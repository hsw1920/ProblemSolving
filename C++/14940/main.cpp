//
//  main.cpp
//  14940
//
//  Created by 홍승완 on 2022/11/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int maps[1001][1001];
int res[1001][1001];
int visited[1001][1001];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cx,cy;



void bfs(){
    queue<pair<pair<int,int>,int>>q;
    q.push({{cx,cy},1});
    res[cx][cy]=0;
    visited[cx][cy]=1;
    while (q.size()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&visited[nx][ny]==0&&maps[nx][ny]==1){
                visited[nx][ny]=1;
                res[nx][ny]=d;
                q.push({{nx,ny},d+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
            if(maps[i][j]==2){
                cx=i;
                cy=j;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res[i][j]=-1;
            if(maps[i][j]==0){
                res[i][j]=0;
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
