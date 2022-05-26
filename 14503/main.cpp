//
//  main.cpp
//  14503
//
//  Created by 홍승완 on 2022/05/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,r,c,d;
int maps[51][51];
int res=0;
// 0 북, 1 동, 2 남, 3 서
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
// d -> 북동남서 0123
// 왼쪽 바라보는것? -> d-1을 확인하면됨!// d가 0일때는 3을 확인!

// 빈칸 0, 벽 1
// 지도의 테두리는 모두 벽이다.

// 왼쪽이 청소안했으면 왼쪽 회전하고 전진하고 청소
// 회전만 4번하면 후진한다. 뒤가 벽이면 작동 멈춤
void rotate_left(){
    d--;
    if(d<0)
        d=3;
}
void go_front(){
    r=r+dx[d];
    c=c+dy[d];
}
void go_back(){
    // 뒤쪽 방향 찾기
    int dd=d-2;
    if(dd==-1)
        dd=3;
    if(dd==-2)
        dd=2;
    //뒤로 이동
    r=r+dx[dd];
    c=c+dy[dd];
}
bool check(){
    // 현재 방향 d
    int dd=d-1;
    if(dd<0)dd=3;
    //왼쪽회전했을 때 방향 dd
    
    int xx=r+dx[dd];
    int yy=c+dy[dd];
    // 청소가능하면 true
    if(maps[xx][yy]==0){
        return true;
    }
    // 아니면 false
    else
        return false;
}
void start(){
    // 현재 방향 d, 좌표 (r,c)
    // 왼쪽확인 4번 -> 후진!
    // 청소한곳은 2로 표시함!
    int cnt=0;
    while(1){
        //현재 위치 청소
        if(maps[r][c]==0){
            maps[r][c]=2;
            res++;
        }
        // 후진
        if(cnt==4){
            go_back();
            cnt=0;
            // 후진했을 때 벽이면 멈추기
            if(maps[r][c]==1){
                break;
            }
        }
        else{
            // 왼쪽이 0이면 회전하고(d--) 전진, cnt=0초기화
            if(check()){
                //왼쪽회전하고 전진
                rotate_left();
                go_front();
                cnt=0;
            }
            else{
                //왼쪽회전하고 cnt++
                rotate_left();
                cnt++;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>r>>c>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
        }
    }
    start();
    cout<<res;
    return 0;
}
