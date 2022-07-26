//
//  main.cpp
//  16236
//
//  Created by 홍승완 on 2022/05/27.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
// 9는 아기상어 위치
// 아기상어의 크기보다 작은 물고기만 먹을 수 있음
int bs=2;
int times=0;
int cnt=0;
int maps[21][21];
int visited[21][21]={0,};
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int r,c; // 현재 아기상어의 위치
int qqq=0;
bool check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(maps[i][j]<bs && maps[i][j]!=0)
                return false;
        }
    }
    return true;
}
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
}
void bfs(){
    int dis=1e9;
    int resX=n,resY=n;
    queue<pair<pair<int,int>,int>>q;
    q.push({{r,c},0});
    visited[r][c]=1;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int k=q.front().second;
        // bfs로는 상,좌 방향 우선을 결정할 수 없으므로
        // 최단거리의 모든 경우를 다 탐색하여 좌표의 크기로 결정하여야 함. // 중요!!!!
        //아기상어가 먹을 수 있는 물고기면
        if(maps[x][y]<bs && maps[x][y]!=0){
            if(dis>=k){
                if(x<resX){
                    resX=x;
                    resY=y;
                    dis=k;
                }
                else if(x==resX){
                    if(y<resY){
                        resX=x;
                        resY=y;
                        dis=k;
                    }
                }
            }
        }
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&yy>=0&&xx<n&&yy<n&&visited[xx][yy]==0&&maps[xx][yy]<=bs){
                visited[xx][yy]=1;
                q.push({{xx,yy},k+1});
            }
        }
    }
    if(resX!=n && resY!=n){
        cnt++;
        times+=dis;
        if(cnt==bs){
            bs++;
            cnt=0;
        }
        maps[resX][resY]=0;
        r=resX;
        c=resY;
    }
    else{
        qqq=1;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
            // 아기상어 위치
            if(maps[i][j]==9){
                r=i;
                c=j;
                maps[r][c]=0;
            }
        }
    }
    // bfs를 통해 먹을 수 있는것 탐색
    // 먹을 물고기 있었으면 visit 초기화하고 재 탐색
    // 없었으면 시간출력
    while(1){
        if(check()){
            cout<<times<<"\n";
            break;
        }
        bfs();
        if(qqq==1){
            cout<<times<<"\n";
            break;
        }
        init();
    }
    return 0;
}
