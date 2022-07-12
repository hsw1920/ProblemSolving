//
//  main.cpp
//  14502
//
//  Created by 홍승완 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int maxNum=0;
int n,m;
int maps[8][8];
int tmp[8][8];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(){
    int tmap[8][8];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmap[i][j]=tmp[i][j];
        }
    }
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(tmap[i][j]==2)
                q.push({i,j});
    
    while(q.size()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&tmap[xx][yy]==0){
                tmap[xx][yy]=2;
                q.push({xx,yy});
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmap[i][j]==0)cnt++;
        }
    }
    maxNum=max(maxNum,cnt);
}

void wall(int cnt){
    if(cnt==3){
        bfs();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j]==0){
                tmp[i][j]=1;
                wall(cnt+1);
                tmp[i][j]=0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 0빈칸, 1벽, 2바이러스
    // 벽개수 3개 반드시 세워야함
    // 0의 최대개수가 안전영역
    // N*M C 3 의 시간복잡도
    // map에 3가지 벽을 세우는 모든 경우에서 각각 dfs돌려서 안전영역최댓값
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]==0){
                for(int q=0;q<n;q++){
                    for(int w=0;w<m;w++){
                        tmp[q][w]=maps[q][w];
                    }
                }
                tmp[i][j]=1;
                wall(1);
                tmp[i][j]=0;
            }
        }
    }
    cout<<maxNum<<"\n";
    
    return 0;
}
