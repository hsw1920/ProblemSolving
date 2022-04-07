//
//  main.cpp
//  2146
//
//  Created by 홍승완 on 2022/04/07.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int map[100][100];
int vis[100][100]={0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int x,int y,int g){
    map[x][y]=g;
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<n&&
           vis[xx][yy]==0&&map[xx][yy]==1){
            dfs(xx,yy,g);
        }
    }
}

int bfs(int x,int y){
    queue<pair<pair<int,int>,int>>q;
    vis[x][y]=1;
    q.push({{x,y},0});
    int gnd=map[x][y];
    while(!q.empty()) {
        int qx=q.front().first.first;
        int qy=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=qx+dx[i];
            int yy=qy+dy[i];
            if(xx>=0&&yy>=0&&xx<n&&yy<n&&
               vis[xx][yy]==0){
                if(map[xx][yy]==0){
                    vis[xx][yy]=1;
                    q.push({{xx,yy},cnt+1});
                }
                //다리를 만듦
                else if(map[xx][yy]!=0&&map[xx][yy]!=gnd){
                    return cnt;
                }
            }
        }
    }
    return 1e9;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    //그룹번호 num
    int num=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==0&&map[i][j]==1){
                dfs(i,j,num);
                num++;
            }
        }
    }
    
    int minN=1e9;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //vis init
            for(int q=0;q<n;q++){
                for(int w=0;w<n;w++){
                    vis[q][w]=0;
                }
            }
            if(map[i][j]!=0){
                minN=min(bfs(i,j),minN);
            }
        }
    }
    cout<<minN;
    return 0;
}
