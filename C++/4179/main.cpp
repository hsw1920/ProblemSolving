//
//  main.cpp
//  4179
//
//  Created by 홍승완 on 2022/03/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pint pair<int,int>
using namespace std;

int r,c;

char maps[1001][1001];
int visited1[1001][1001];
int visited2[1001][1001];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pint>p1,p2; //홀수시간, 짝수시간
queue<pint>q1,q2;
int t=0;
int escape=0;
void bfs(){
    //짝수시간일때
    if(t%2==0){
        //p1의 위치의 지훈이의 다음 위치를 모두 p2에 저장
        //q1의 위치의 불의 다음 위치를 모두 q2에 저장
        while(p1.size()){
            int x=p1.front().first;
            int y=p1.front().second;
            p1.pop();
            if(maps[x][y]=='F')continue;
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                // 탈출하는 경우?
                if(xx<0||xx>=r||yy<0||yy>=c){
                    escape=1;
                    return;
                }
                if(visited1[xx][yy]==0&&maps[xx][yy]=='.'){
                    visited1[xx][yy]=1;
                    p2.push({xx,yy});
                }
            }
        }
        while(q1.size()){
            int x=q1.front().first;
            int y=q1.front().second;
            q1.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0&&xx<r&&yy>=0&&yy<c&&visited2[xx][yy]==0&&maps[xx][yy]=='.'){
                    visited2[xx][yy]=1;
                    maps[xx][yy]='F';
                    q2.push({xx,yy});
                }
            }
        }
    }
    //홀수시간일때
    else{
        //p2의 위치의 지훈이의 다음 위치를 모두 p1에 저장
        //q2의 위치의 불의 다음 위치를 모두 q1에 저장
        while(p2.size()){
            int x=p2.front().first;
            int y=p2.front().second;
            p2.pop();
            if(maps[x][y]=='F')continue;
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                // 탈출하는 경우?
                if(xx<0||xx>=r||yy<0||yy>=c){
                    escape=1;
                    return;
                }
                if(visited1[xx][yy]==0&&maps[xx][yy]=='.'){
                    visited1[xx][yy]=1;
                    p1.push({xx,yy});
                }
            }
        }
        while(q2.size()){
            int x=q2.front().first;
            int y=q2.front().second;
            q2.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0&&xx<r&&yy>=0&&yy<c&&visited2[xx][yy]==0&&maps[xx][yy]=='.'){
                    visited2[xx][yy]=1;
                    maps[xx][yy]='F';
                    q1.push({xx,yy});
                }
            }
        }
    }
    
    //cout<<t<<" p1.size:"<<p1.size()<<"\n";
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        cin>>str;
        for(int j=0;j<c;j++){
            maps[i][j]=str[j];
            if(str[j]=='J'){
                p2.push({i,j});
                visited1[i][j]=1;
                maps[i][j]='.';
            }
            if(str[j]=='F')
                q2.push({i,j});
        }
    }
    while(1){
        t++;
        bfs();
        // 탈출한경우
        // t출력, break;
        if(escape==1){
            cout<<t<<"\n";
            break;
        }
        // 탈출못하는경우
        // IMPOSSIBLE 출력 break;
        if(t%2==1&&p1.size()==0){
            cout<<"IMPOSSIBLE\n";
            break;
        }
        else if(t%2==0&&p2.size()==0){
            cout<<"IMPOSSIBLE\n";
            break;
        }
    }
    return 0;
}
