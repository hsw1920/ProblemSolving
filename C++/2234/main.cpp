//
//  main.cpp
//  2234
//
//  Created by 홍승완 on 2022/08/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;
int maps[51][51];
int visited[51][51];
// 서북동남
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int n,m;

int tmp=0;
int ans1=0;
int ans2=0;
// 방개수, 큰방넓이, 벽하나 없애고 큰방넓이
int ans3=0;

void dfs(int x, int y){
    int cur=maps[x][y];
    tmp++;
    for(int i=0;i<4;i++){
        // 벽이 없는곳이면
        if(!(cur & (1<<i))){
            int xx=x+dx[i];
            int yy=y+dy[i];
            // 방문안하고 갈 수 있는곳이면
            if(xx>=0&&xx<n&&yy>=0&&yy<m &&visited[xx][yy]==0){
                visited[xx][yy]=1;
                dfs(xx,yy);
            }
        }
    }
}

int bfs(int x, int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    int cnt=1;
    while(q.size()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            if(!(maps[x][y] & (1<<i))){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0&&xx<n&&yy>=0&&yy<m &&visited[xx][yy]==0){
                    visited[xx][yy]=1;
                    cnt++;
                    q.push({xx,yy});
                }
            }
        }
        
    }
    return cnt;
}

// 방개수
void solve1(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0){
                tmp=0;
                visited[i][j]=1;
                dfs(i,j);
                ans1++;
                ans2=max(ans2,tmp);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
        }
    }
    solve1(); // 방 개수
    cout<<ans1<<"\n";
    cout<<ans2<<"\n";
    //cout<< (!(5 & (1<<0)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                if(maps[i][j] & (1<<k)){
                    // init
                    for(int q=0;q<n;q++)
                        for(int w=0;w<m;w++)
                            visited[q][w]=0;
                    //
                    maps[i][j]-=(1<<k);
                    ans2=max(ans2,bfs(i,j));
                    maps[i][j]+=(1<<k);
                }
            }
        }
    }
    cout<<ans2;
    return 0;
}
