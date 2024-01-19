//
//  main.cpp
//  16234
//
//  Created by 홍승완 on 2024/01/17.
//

#include <bits/stdc++.h>
using namespace std;
int n,r,c,L,R;
int maps[51][51];
int visited[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int>>tmp;
vector<vector<pair<int,int>>>v;
void dfs(int x, int y){
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0||yy<0||xx>=n||yy>=n||visited[xx][yy]==1)continue;
        if(abs(maps[x][y]-maps[xx][yy])>=L&&abs(maps[x][y]-maps[xx][yy])<=R){
            tmp.push_back({xx,yy});
            visited[xx][yy]=1;
            dfs(xx, yy);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>L>>R;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
    
    // 국경선 공유하는 인구차이가 L명이상 R명이하라면 1일동안 국경선을 엶
    // 국경선이 열린 국가는 연합이 됨 (같은 연결요소가 됨)
    // 연합을 이루는 각 칸의 인구수는 총인구/칸수 가 된다.
    
    // 1. 하루마다 연결요소를 찾는다.
    // 2. 연결요소의 인구이동을 진행한다.
    // 3. 인구이동이 없을때까지 반복한다.
    
    int day=0;
    while(1){
        // 인구이동여부 변수
        bool chk = false;
        
        // init
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)visited[i][j]=0;
        v.clear();
        
        // 연결요소 찾기
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0){
                    tmp.clear();
                    tmp.push_back({i,j});
                    visited[i][j]=1;
                    dfs(i,j);
                    v.push_back(tmp);
                }
            }
        }
        // 여기서 완전탐색을 통해 연결요소들이 v에 모두 저장됨
        
        // 인구이동하면서 변수 토글
        for(auto k:v){
            // 연결요소 개수가 1보다크면 인구이동이 있음.
            if(k.size()>1)chk=true;
            
            int sum=0;
            // sum에 연결요소의 인구합저장
            for(auto elem: k){
                sum+=maps[elem.first][elem.second];
            }
            sum/=k.size(); // 인구평균으로 나눔
            
            // 해당 연결요소들에 인구를 나눔
            for(auto elem: k){
                maps[elem.first][elem.second] = sum;
            }
        }
        
        // 인구이동 없었으면 break
        if(!chk)break;
        day++;
    }
    cout<<day<<"\n";
    
    return 0;
}
