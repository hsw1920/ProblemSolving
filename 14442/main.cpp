//
//  main.cpp
//  14442
//
//  Created by 홍승완 on 2022/04/04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n,m,k;
bool vis[1001][1001][11]={0,};
int map[1001][1001];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(){
    queue<pair<pair<int,int>,pair<int,int>>>q;
    vis[0][0][k]=1;
    q.push({{0,0},{k,1}});
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second.first;
        int d=q.front().second.second;
        if(x==n-1&&y==m-1){
            cout<<d;
            return;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(vis[xx][yy][cnt]==0&&xx>=0&&yy>=0&&xx<n&&yy<m){
                // 벽이 아닐때
                if(map[xx][yy]==0){
                    vis[xx][yy][cnt]=1;
                    q.push({{xx,yy},{cnt,d+1}});
                }
                // 벽일 때 => 부수고가야함 k까지
                else if(map[xx][yy]==1){
                    //부술 수 있으면 부수고 q에 삽입
                    if(cnt>0){
                        vis[xx][yy][cnt]=1;
                        q.push({{xx,yy},{cnt-1,d+1}});
                    }
                    //못 부수면 continue
                    else{
                        continue;
                    }
                }
            }
        }
    }
    cout<<-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            map[i][j]=str[j]-'0';
        }
    }
    bfs();
    
    return 0;
}
