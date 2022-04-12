//
//  main.cpp
//  1600
//
//  Created by 홍승완 on 2022/04/12.
//

#include <iostream>
#include <queue>
using namespace std;
int map[201][201];
int vis[201][201][31]={0,};
int dx[12]={0,0,1,-1,1,1,-1,-1,2,2,-2,-2};
int dy[12]={1,-1,0,0,2,-2,2,-2,1,-1,1,-1};
int k,w,h;

int bfs(){
    queue<pair<pair<int,int>,pair<int,int>>>q;
    vis[0][0][k]=1;
    q.push({{0,0},{k,0}});
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second.first; // 대각이동
        int len=q.front().second.second; // 이동횟수
        q.pop();
        if(x==h-1&&y==w-1){
            return len;
        }
        //인접
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&yy>=0&&xx<h&&yy<w&&map[xx][yy]==0&&vis[xx][yy][cnt]==0){
                //인접방향
                vis[xx][yy][cnt]=1;
                q.push({{xx,yy},{cnt,len+1}});
            }
        }
        if(cnt==0)continue;
        //대각
        for(int i=4;i<12;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&yy>=0&&xx<h&&yy<w&&map[xx][yy]==0&&vis[xx][yy][cnt-1]==0){
                //대각방향 -> k번만 -> vis[][][k]
                vis[xx][yy][cnt-1]=1;
                q.push({{xx,yy},{cnt-1,len+1}});
            }
        }
        for(int i=0;i<12;i++){
            
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;
    cin>>w>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>map[i][j];
        }
    }
    //시작점 (0,0)
    //도착점 (h-1,w-1);
    cout<<bfs();
    return 0;
}
