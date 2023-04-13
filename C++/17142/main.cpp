//
//  main.cpp
//  17142
//
//  Created by 홍승완 on 2023/04/12.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int maps[51][51],virus[10];
int visited[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m,zero;
int res=1e9;
vector<pair<int,int>>v,tmp;

// 빈칸 0, 벽 1, 바이러스 2
// 바이러스(2)는 m이상 10이하

void bfs(int size){
    queue<pair<int,int>>q;
    memset(visited, -1, sizeof(visited));
    for(int i=0;i<size;i++){
        if(virus[i]==1){
            q.push({v[i].first,v[i].second});
            visited[v[i].first][v[i].second]=0;
        }
    }
    int chk=0;
    int time=0;
    while(q.size()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&yy>=0&&xx<n&&yy<n&&maps[xx][yy]!=1){
                if(visited[xx][yy]==-1){
                    visited[xx][yy]=visited[x][y]+1;
                    if(maps[xx][yy]==0){
                        chk++;
                        time=visited[xx][yy];
                    }
                    q.push({xx,yy});
                }
            }
        }
    }
    if(chk==zero)
        res=min(res,time);
    
}

void setVirus(int idx, int cnt, int size){
    if(cnt==m){
        bfs(size);
        return;
    }
    for(int i=idx;i<size;i++){
        if(virus[i]==0){
            virus[i]=1;
            setVirus(i+1, cnt+1, size);
            virus[i]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
            if(maps[i][j]==2){
                v.push_back({i,j});
            }
            if (maps[i][j]==0){
                zero++;
            }
        }
    }
    setVirus(0,0,v.size());

    if(res==1e9)cout<<-1;
    else {
        cout<<res;
    }

    return 0;
}
