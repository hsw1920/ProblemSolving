//
//  main.cpp
//  2583
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maps[101][101];
int visited[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cnt=0;
int wh=0;
int n,m,k;
vector<int>v;
void dfs(int x, int y){
    visited[x][y]=1;
    wh++;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&visited[xx][yy]==0&&maps[xx][yy]==0){
            dfs(xx,yy);
        }
    }
}
int main() {
    
    // map의 x, y가 뒤바뀌어서 매우 혼란스러움
    // 명확하게 좌표를 설계해야하는 문제
    // 스스로 좌표 x,y를 어떻게 배열로 구현할 것인가?
    cin>>m>>n>>k;
    int x1,x2,y1,y2;
    for(int i=0;i<k;i++){
        cin>>y1>>x1>>y2>>x2;
        //
        for(int j=y1;j<y2;j++){
            for(int w=x1;w<x2;w++){
                maps[j][w]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            wh=0;
            if(visited[i][j]==0&&maps[i][j]==0){
                // dfs를 통해서 나누어진 나누어진영역들을 집합화하고 카운팅
                dfs(i,j);
                cnt++;
                // dfs의 depth(넓이)를 따로 벡터에 저장함
                v.push_back(wh);
            }
        }
    }
    cout<<cnt<<"\n";
    
    // 벡터에 저장된 분리집합들의 넓이들을 오름차순 정렬
    sort(v.begin(),v.end());
    // 출력
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

