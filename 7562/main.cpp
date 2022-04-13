//
//  main.cpp
//  7562
//
//  Created by 홍승완 on 2022/04/13.
//

#include <iostream>
#include <queue>
using namespace std;

int T,I;
int cx,cy,tx,ty;
int map[301][301];
int vis[301][301];
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

queue<pair<int,int>> q;

void bfs(int x,int y) {
    q.push({x,y});
    vis[x][y]=true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==tx && y==ty) {
            cout <<map[x][y] << "\n";
            while(!q.empty()) {
                q.pop();
            }
            break;
        }
        for(int i=0;i<8;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(0<=xx && 0<=yy && xx <I && yy < I && !vis[xx][yy]) {
                q.push({xx,yy});
                vis[xx][yy]=1;
                map[xx][yy]=map[x][y]+1;
            }
        }
    }
}

int main() {
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> I;
        cin >> cx >> cy;
        cin >> tx >> ty;
        
        bfs(cx,cy);
        
        //init
        while (!q.empty()){
            q.pop();
        }
        for (int i = 0; i < 301; i++) {
            for (int j = 0; j < 301; j++) {
                vis[i][j] = 0;
                map[i][j] = 0;
            }
        }
    }
}
