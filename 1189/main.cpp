//
//  main.cpp
//  1189
//
//  Created by 홍승완 on 2022/07/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;
int r,c,k;
int maps[5][5];
int visited[5][5];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int res=0;
void dfs(int x,int y,int d){
    if(d==k){
        if(x==0&&y==c-1){
            res++;
        }
        return ;
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<r&&yy>=0&&yy<c&&maps[xx][yy]==1&&visited[xx][yy]==0){
            visited[xx][yy]=1;
            dfs(xx,yy,d+1);
            visited[xx][yy]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c>>k;
    string s;
    for(int i=0;i<r;i++){
        cin>>s;
        for(int j=0;j<c;j++){
            if(s[j]=='.')maps[i][j]=1;
            else maps[i][j]=0;
        }
    }
    visited[r-1][0]=1;
    dfs(r-1,0,1);
    cout<<res<<"\n";
    
    return 0;
}
