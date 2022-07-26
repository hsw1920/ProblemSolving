//
//  main.cpp
//  1012
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maps[51][51];
int visited[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m,k;
void init(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            maps[i][j]=0;
            visited[i][j]=0;
        }
    }
}

void dfs(int x, int y){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&visited[xx][yy]==0&&maps[xx][yy]==1){
            dfs(xx,yy);
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int cnt=0;
        init();
        cin>>m>>n>>k;
        int tx,ty;
        while(k--){
            cin>>ty>>tx;
            maps[tx][ty]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && maps[i][j]==1){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
