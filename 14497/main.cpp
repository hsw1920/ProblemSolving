//
//  main.cpp
//  14497
//
//  Created by 홍승완 on 2022/07/20.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

// 주난(*), 초코바(#), 빈공간(0), 친구(1)
int n,m;
int x1,y1,x2,y2;
char maps[301][301];
int visited[301][301];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            visited[i][j]=0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;
    x1-=1;
    y1-=1;
    x2-=1;
    y2-=1;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            maps[i][j]=str[j];
        }
    }
    int cnt=0;
    while(1){
        init();
        queue<pair<int,int>>q;
        q.push({x1,y1});
        visited[x1][y1]=1;
        cnt++;
        while(q.size()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx==x2&&yy==y2){
                    cout<<cnt<<"\n";
                    return 0;
                }
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&visited[xx][yy]==0&&maps[xx][yy]=='0'){
                    visited[xx][yy]=1;
                    q.push({xx,yy});
                }
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&visited[xx][yy]==0&&maps[xx][yy]=='1'){
                    visited[xx][yy]=1;
                    maps[xx][yy]='0';
                }
                
            }
        }
    }
    
    return 0;
}
