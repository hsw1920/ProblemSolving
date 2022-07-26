//
//  main.cpp
//  11967
//
//  Created by 홍승완 on 2022/04/08.
//

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define pint pair<int,int>

using namespace std;

int n,m;
int maps[101][101]={0,};
int vis[101][101]={0,};
int ax,by,a,b;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pint>mp[101][101];
int maxNum=1;
void bfs(){
    queue<pint>q;
    q.push({1,1});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<mp[x][y].size();i++){
            if(maps[mp[x][y][i].first][mp[x][y][i].second]==0){
                maps[mp[x][y][i].first][mp[x][y][i].second]=1;
                maxNum++;
                // 새로운 방 불이켜지면 되돌아온길 vis를 초기화해야 지나온길로 되돌아갈 수 있음
                for(int q=1;q<=n;q++){
                    for(int w=1;w<=n;w++)
                        vis[q][w]=0;
                }
            }
        }
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=1&&yy>=1&&xx<=n&&yy<=n
               &&vis[xx][yy]==0&&maps[xx][yy]==1){
                vis[xx][yy]=1;
                q.push({xx,yy});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    maps[1][1]=1;
    for(int i=1;i<=m;i++){
        cin>>ax>>by>>a>>b;
        mp[ax][by].push_back({a,b});
    }
    bfs();
    cout<<maxNum;
    return 0;
}
