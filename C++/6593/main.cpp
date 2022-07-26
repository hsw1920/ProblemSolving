//
//  main.cpp
//  6593
//
//  Created by 홍승완 on 2022/03/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int C,R,L;
// 시작지점 S, 출구 E, 장애물 #, 빈칸 .
// L번, R개의행 C개의 문자(열)
int sd,sx,sy,ed,ex,ey;
char map[31][31][31];
bool visited[31][31][31];
int dd[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};
int bfs(){
    queue<pair<pair<int,int>,pair<int,int>>>q;
    visited[sd][sx][sy]=true;
    q.push({{sd,0},{sx,sy}});
    while (!q.empty()) {
        int cd,cx,cy,cnt;
        cd=q.front().first.first;
        cnt=q.front().first.second;
        cx=q.front().second.first;
        cy=q.front().second.second;
        if(map[cd][cx][cy]=='E'){
            return cnt;
        }
        q.pop();
        for(int i=0;i<6;i++){
            int nd=cd+dd[i];
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(!visited[nd][nx][ny]){
                if(nd>=0&&nx>=0&&ny>=0
                   &&nd<L&&nx<R&&ny<C
                   &&map[nd][nx][ny]!='#'){
                    // #1 BFS는 방문처리를 큐에 넣을 시 해야함!!!
                    // 여러 정점에서 한 정점을 동시에 방문하려 할 수 있기 때문!!
                    visited[nd][nx][ny]=true;
                    q.push({{nd,cnt+1},{nx,ny}});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //TC는 LRC가 0을입력받을때까지 반복
    while(1){
        // #2 제발 초기화배열 신경쓰자
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    visited[i][j][k]=false;
                }
            }
        }
        cin>>L>>R>>C;
        if(L==0&&R==0&&C==0)
            break;
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    cin>>map[i][j][k];
                    if(map[i][j][k]=='S'){
                        sd=i;sx=j;sy=k;
                    }
                    if(map[i][j][k]=='E'){
                        ed=i;ex=j;ey=k;
                    }
                }
            }
        }
        int result=bfs();
        if(result==-1){
            cout<<"Trapped!\n";
        }
        else{
            cout<<"Escaped in "<<result<<" minute(s).\n";
        }
    }
    return 0;
}
