//
//  main.cpp
//  2589
//
//  Created by 홍승완 on 2022/07/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
int maps[51][51]={0,};
int visited[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int res=0;
vector<pair<int,int>>v;

void bfs(int x, int y){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
    int pres=0;
    visited[x][y]=1;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{x,y}});
    while(q.size()){
        x=q.front().second.first;
        y=q.front().second.second;
        int cnt=q.front().first;
        pres=max(pres,cnt);
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&visited[nx][ny]==0&&maps[nx][ny]==1){
                visited[nx][ny]=1;
                q.push({cnt+1,{nx,ny}});
            }
        }
    }
    res=max(res,pres);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //육지L 바다W
    // 보물은 육지간 최단거리중 가장 먼곳인 두곳에 묻힘
    cin>>n>>m;
    string tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        for(int j=0;j<m;j++){
            if(tmp[j]=='L'){
                maps[i][j]=1;
                v.push_back({i,j}); // 육지좌표만 푸시
            }
        }
    }
    for(int i=0;i<v.size();i++){
        int x=v[i].first;
        int y=v[i].second;
        bfs(x,y); // bfs를 통해 각 육지 좌표에서 최단거리를 구하여 최댓값을 갱신함
        // 최댓값인경우 보물이 묻혀있는 최단거리임.
        // bfs를 통해 구해야 육지간 돌아가지않는 최단거리임. dfs의 경우 돌아가는 방향이 나올 수 있음
    }
    cout<<res<<"\n";
    return 0;
}
