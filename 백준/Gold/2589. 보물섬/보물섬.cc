//
//  main.cpp
//  2589
//
//  Created by 홍승완 on 2024/01/17.
//

#include <bits/stdc++.h>
using namespace std;
int n,m,visited[51][51],res=0;
char maps[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int>>tresure;
void bfs(int x, int y){
    for(int q=0;q<n;q++)
        for(int w=0;w<m;w++)
            visited[q][w]=0;
    
    visited[x][y]=1;
    
    queue<pair<int,int>>q;
    q.push({x,y});
    while(q.size()){
        int xx=q.front().first;
        int yy=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=xx+dx[i];
            int ny=yy+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]!=0||maps[nx][ny]=='W')continue;
            visited[nx][ny]=visited[xx][yy]+1;
            q.push({nx,ny});
        }
    }
    int ret=0;
    for(int q=0;q<n;q++){
        for(int w=0;w<m;w++){
            ret=max(ret,visited[q][w]);
        }
    }

    res=max(res,ret);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            maps[i][j]=str[j];
            if(str[j]=='L')tresure.push_back({i,j});
        }
    }
    
    // 거기서 bfs
    for(int i=0;i<tresure.size();i++){
        bfs(tresure[i].first,tresure[i].second);
    }
    cout<<res-1<<"\n";
    return 0;
}
