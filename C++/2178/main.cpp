//
//  main.cpp
//  2178
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int maps[101][101];
int visited[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main() {
    cin>>n>>m;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            maps[i][j]=str[j]-'0';
        }
    }
    queue<pair<pair<int,int>,int>>q;
    q.push({{0,0},1});
    visited[0][0]=1;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        if(x==n-1&&y==m-1){
            cout<<cnt<<"\n";
            break;;
        }
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&visited[xx][yy]==0&&maps[xx][yy]==1){
                visited[xx][yy]=1;
                q.push({{xx,yy},cnt+1});
            }
        }
    }
    return 0;
}

