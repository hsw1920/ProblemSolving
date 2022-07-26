//
//  main.cpp
//  2468
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int maps[101][101];
int visited[101][101];
int cnt=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void init(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            visited[i][j]=0;
}

void dfs(int x, int y, int h){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<n&&visited[xx][yy]==0&&maps[xx][yy]>h){
            dfs(xx,yy,h);
        }
    }
}

int main() {
    // 물이 차오를 때마다 잠기지 않은 영역인 안전영역의 개수는 달라진다.
    // 이때 차오르는 물 높이에 따른 안전영역의 최대 수를 출력
    // 각 높이 h일 때마다 dfs를 통해서 안전영역집합 수 cnt 카운팅 -> max(cnt)
    // 높이는 1...100
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
    
    for(int h=1;h<=100;h++){
        int tmp=0;
        init(); // visited 초기화
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // h 이하인곳은 물에 잠김
                if(maps[i][j]>h && visited[i][j]==0){
                    dfs(i,j,h);
                    tmp++;
                }
            }
        }
        cnt=max(cnt,tmp);
    }
    // 아무곳도 잠기지 않았을 때 경우에는 안전영역을 셀 수 없으므로
    // 해당 경우 추가
    if(cnt==0)cnt=1;
    cout<<cnt<<"\n";
    
    return 0;
}
