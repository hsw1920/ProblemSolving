//
//  main.cpp
//  14499
//
//  Created by 홍승완 on 2023/05/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k,xx,yy,op;
int maps[21][21];
int up=0;
int bottom=0;
int east=0;
int west=0;
int north=0;
int south=0;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
// 동서북남
void roll(int op, int x, int y){
    int nx=x+dx[op-1];
    int ny=y+dy[op-1];
    if(nx<0||ny<0||nx>=n||ny>=m)
        return;
    if(op==1){
        // 일단 굴리고 출력
        int tmp=up;
        up=west;
        west=bottom;
        bottom=east;
        east=tmp;
        // 바닥
        if(maps[x][y+1]==0){
            maps[x][y+1]=bottom;
        } else {
            bottom = maps[x][y+1];
            maps[x][y+1]=0;
        }
        yy+=1;
    }
    else if(op==2){
        // 일단 굴리고 출력
        int tmp=up;
        up=east;
        east=bottom;
        bottom=west;
        west=tmp;
        // 바닥
        if(maps[x][y-1]==0){
            maps[x][y-1]=bottom;
        } else {
            bottom = maps[x][y-1];
            maps[x][y-1]=0;
        }
        yy-=1;
    }
    else if(op==3){
        // 일단 굴리고 출력
        int tmp=up;
        up=south;
        south=bottom;
        bottom=north;
        north=tmp;
        // 바닥
        if(maps[x-1][y]==0){
            maps[x-1][y]=bottom;
        } else {
            bottom = maps[x-1][y];
            maps[x-1][y]=0;
        }
        xx-=1;
    }
    else{
        // 일단 굴리고 출력
        int tmp=up;
        up=north;
        north=bottom;
        bottom=south;
        south=tmp;
        // 바닥
        if(maps[x+1][y]==0){
            maps[x+1][y]=bottom;
        } else {
            bottom = maps[x+1][y];
            maps[x+1][y]=0;
        }
        xx+=1;
        
    }
    cout<<up<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>xx>>yy>>k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
        }
    }
    
    // (x,y)가 주사위가 놓인 칸
    for(int i=0;i<k;i++){
        cin>>op;
        roll(op, xx, yy);
    }
    
    return 0;
}
