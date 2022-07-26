//
//  main.cpp
//  3197
//
//  Created by 홍승완 on 2022/07/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

//  물(.), 빙판(X), 백조(L)
// 물과 접촉한 빙판은 모두 녹는다
// 완탐+dfs를 통해서 빙판을 물로 바꿈
// 백조는 두마리

// 사이클
// 백조만나는지 확인 + 빙판녹이기 + cnt++ -> 반복

int r,c,day=0;
char maps[1501][1501];
bool visited[1501][1501];
bool visited_swan[1501][1501];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<pair<int,int>>swan;
queue<pair<int,int>>swanQ,swanQ_tmp,waterQ,waterQ_tmp;
queue<pair<int,int>>emptyQ;

bool isMeet=false;

void melting(){
    while(waterQ.size()){
        int x=waterQ.front().first;
        int y=waterQ.front().second;
        waterQ.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&xx<r&&yy>=0&&yy<c&&visited[xx][yy]==0){
                if(maps[xx][yy]=='X'){
                    visited[xx][yy]=1;
                    waterQ_tmp.push({xx,yy});
                    maps[xx][yy]='.';
                }
            }
        }
    }
}

void move_swan(){
    while(swanQ.size()){
        int x= swanQ.front().first;
        int y=swanQ.front().second;
        swanQ.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&xx<r&&yy>=0&&yy<c&&visited_swan[xx][yy]==0){
                if(maps[xx][yy]=='.')swanQ.push({xx,yy});
                else if(maps[xx][yy]=='X')swanQ_tmp.push({xx,yy});
                else if(maps[xx][yy]=='L'){isMeet=true;return;}
                visited_swan[xx][yy]=1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c;
    string str;
    for(int i=0;i<r;i++){
        cin>>str;
        for(int j=0;j<c;j++){
            maps[i][j]=str[j];
            if(str[j]=='L')swan.push_back({i,j}); // 백조좌표저장
            if(str[j]=='.'||str[j]=='L'){
                visited[i][j]=1;
                waterQ.push({i,j});
            }
        }
    }
    swanQ.push({swan[0].first,swan[0].second});
    visited_swan[swan[0].first][swan[0].second]=1;
    while(!isMeet){
        // 백조 만나는지 확인
        move_swan();
        if(isMeet)break;
        melting();
        waterQ=waterQ_tmp;
        swanQ=swanQ_tmp;
        waterQ_tmp=emptyQ;
        swanQ_tmp=emptyQ;
        day++;
    }
    cout<<day<<"\n";
    
    return 0;
}
