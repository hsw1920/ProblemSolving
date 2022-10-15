//
//  main.cpp
//  5427
//
//  Created by 홍승완 on 2022/10/15.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// . 빈공간
// # 벽
// @ 시작위치 -> 유일
// * 불

// 불이 먼저 퍼지고 상근'@'이동
// 불은 동서남북 빈공간으로 퍼짐, 벽에는 불안붙
// 불이 옮겨질칸, 불이퍼진칸은 이동x

// res -> 빌딩 탈출 최소시간 출력
// 탈출 못하면 IMPOSSIBLE 출력

int T;
char maps[1002][1002];
char fr[1002][1002];
int fire[1002][1002];
//int sang[1002][1002];
bool visited[1002][1002];

//int visited1[1002][1002];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int w,h;
int x,y;
int cnt = 1e9;

//vector<pair<int,int>>fires;
//queue<pair<pair<int,int>,int>>q;

void init(){
    //fire 초기화
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            visited[i][j]=0;
            //visited1[i][j]=0;
        }
    }
}
void init2(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            //sang[i][j]=1e9;
            fire[i][j]=1e9;
        }
    }
}

void fireBfs(int cx, int cy){
    init();
    queue<pair<pair<int,int>,int>>q;
    //while(q.size())q.pop();
    q.push({{cx,cy},0});
    fr[cx][cy]='*';
    
    while(q.size()){
        int nx=q.front().first.first;
        int ny=q.front().first.second;
        int d = q.front().second;
        fire[nx][ny]=min(fire[nx][ny],d);
        q.pop();
        for(int i=0;i<4;i++){
            int xx = nx+dx[i];
            int yy = ny+dy[i];
            
//            if(xx>=0&&xx<h&&yy>=0&&yy<w&&visited[xx][yy]==0 && maps[xx][yy]!='#'&&maps[xx][yy]!='*'){
//                visited[xx][yy]=1;
//                q.push({{xx,yy},d+1});
//            }
            if(visited[xx][yy]==0&&xx>=0&&xx<h&&yy>=0&&yy<w&& maps[xx][yy]!='#'&&fr[xx][yy]!='*' &&d+1<fire[xx][yy]){
                visited[xx][yy]=1;
                fr[cx][cy]='*';
                q.push({{xx,yy},d+1});
            }
            
        }
    }
    
}




void moveSangeun(){
    
    queue<pair<pair<int,int>,int>>q;
    //while(q.size())q.pop();
    q.push({{x,y},0});
    
    while(q.size()){
        int nx=q.front().first.first;
        int ny = q.front().first.second;
        int d = q.front().second;
        //sang[nx][ny]=min(sang[nx][ny],d);
        q.pop();
        for(int i=0;i<4;i++){
            int xx = nx+dx[i];
            int yy = ny+dy[i];
            
            if(xx>=0&&xx<h&&yy>=0&&yy<w){
//                if( visited[xx][yy]==0 && maps[xx][yy]=='.'&& d+1 < fire[xx][yy]) {
//                    visited[xx][yy]=1;
//                    q.push({{xx,yy},d+1});
//                }
                if(maps[xx][yy]=='.'&& d+1 < fire[xx][yy]) {
                    q.push({{xx,yy},d+1});
                }
            }

            else {
                cnt=min(cnt,d+1);
            }
            
        }
    }
     
}

int main() {
    cin>>T;
    while(T--){
        cnt=1e9;
        cin>>w>>h; // 너비 높이
        //init();
        init2();
        // 맵 채우기
        
        x = 1e9;
        y = 1e9;
        
        vector<pair<int,int>>fires;
        //        fires.clear();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>maps[i][j];
                if(maps[i][j]=='@') {
                    x=i;
                    y=j;
                }
                else if (maps[i][j]=='*'){
                    fires.push_back({i,j});
                }
            }
        }
        
        // fire의 이동시간이 bfs를 통해 fire에 담김
        
        for(auto i: fires){
            fireBfs(i.first, i.second);
        }
        
//        init();
        if(x==1e9&&y==1e9){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        moveSangeun();
        
//        cout<<"\n";
//        for(int i=0;i<h;i++){
//            for(int j=0;j<w;j++){
//                if(fire[i][j]==1e9) cout<<"N";
//                else cout<<fire[i][j];
////                if(sang[i][j]==1e9) cout<<"N";
////                else cout<<sang[i][j];
//            }
//            cout<<"\n";
//        }
//        cout<<"-----\n";

        
        if(cnt==1e9){
            cout<<"IMPOSSIBLE\n";
        } else {
            cout<<cnt<<"\n";
        }
        
    }
    
    return 0;
}
