//
//  main.cpp
//  2210
//
//  Created by 홍승완 on 2023/05/14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maps[6][6];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int set[1000001];
int num=0;
int res=0;
void dfs(int x, int y, int cnt){
    if(cnt==6){
        if(set[num]==0){
            set[num]=1;
            res++;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&yy>=0&&xx<5&&yy<5){
            num*=10;
            num+=maps[xx][yy];
            dfs(xx,yy,cnt+1);
            num-=maps[xx][yy];
            num/=10;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>maps[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            num=maps[i][j];
            dfs(i,j,1);
        }
    }
    cout<<res<<"\n";
    
    
    return 0;
}
