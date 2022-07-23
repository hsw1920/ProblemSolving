//
//  main.cpp
//  14620
//
//  Created by 홍승완 on 2022/07/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int maps[11][11];
int visited[11][11];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int res=1e9;

void init(int x, int y){
    visited[x][y]=0;
    visited[x-1][y]=0;
    visited[x][y-1]=0;
    visited[x+1][y]=0;
    visited[x][y+1]=0;
}

bool isVal(int x,int y){
    if(visited[x][y])return false;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0||yy<0||yy>=n||xx>=n){
            return false;
        }
        if(visited[xx][yy]==1){
            return false;
        }
    }
    visited[x][y]=1;
    visited[x-1][y]=1;
    visited[x][y-1]=1;
    visited[x+1][y]=1;
    visited[x][y+1]=1;
    return true;
}

void go(int cnt){
    // 종료조건 꽃 3개심었을 때
    if(cnt==3){
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==1){
                    sum+=maps[i][j];
                }
            }
        }
        res=min(res,sum);
        return ;
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            if(isVal(i,j)){
                go(cnt+1);
                init(i,j); // i,j좌표 visited초기화
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
    
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            if(isVal(i,j)){
                go(1);
                init(i,j); // i,j좌표 visited초기화
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}
