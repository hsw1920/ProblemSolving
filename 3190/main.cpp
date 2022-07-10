//
//  main.cpp
//  3190
//
//  Created by 홍승완 on 2022/05/31.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
// 뱀은 머리를 다음칸
// 사과가 있으면 사과없어짐 -> 몸길이 1 증가
// 없으면 꼬리칸을 비워줌 -> 몸길이는 그대로

// 벽이나 자기 몸에 부딪히면 게임 끝
int n,k,l;
char c; // T초에 L좌 or D우 90도만큼 방향회전

//뱀의 길이는 최초 1, (0,0)에 위치하고 오른쪽을 향함

int maps[101][101];
// 머리와 꼬리의 위치를 알고있어야함.
// 머리는 현재 방향을 알고있어야함
// i 초마다 머리움직임,꼬리삭제, 사과먹기, 게임끝여부를 판단해야함

int T=0; // 시간
int x_head,y_head,x_tail,y_tail; // 머리와 꼬리
char direction[10001]; // idx초에 방향전환 저장
int direc=0; // 우로 시작 L이면 --, D이면 ++해주면됨
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0}; // 우 하 좌 상
queue<pair<int,int>>tail;
int move(int x,int y){
    //머리가 움직일 위치
    int xx=x+dx[direc];
    int yy=y+dy[direc];
    //다음 꼬리위치
    tail.push({xx,yy});
    
    // 움직인 위치가 벽이거나 자기 몸일경우
    if(xx<0||yy<0||xx>=n||yy>=n || maps[xx][yy]==2) return 0;
    
    // 사과가 있으면
    else if(maps[xx][yy]==1){
        maps[xx][yy]=2; //하고 끝
        return 1;
    }
    else if(maps[xx][yy]==0){
        maps[xx][yy]=2; // 하고 꼬리 지우기
        return 2;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>k;
    int q,w;
    while(k--){
        cin>>q>>w;
        maps[q-1][w-1]=1; // 행렬은 0 부터 시작할꺼임
    }
    cin>>l;
    int tmp;
    while(l--){
        cin>>tmp>>c;
        direction[tmp]=c;
    }
    x_head=y_head=0;
    tail.push({x_tail,y_tail});
    maps[0][0]=2; // 뱀은 2로 표시
    
    while(1){
        T++; // 시간증가
        // 가장먼저 몸길이 늘려서 머리를 다음칸 위치시킬것임 => 벽일경우 or 자기 몸에 부딪힌경우에는 게임끝
        int nxt=move(x_head,y_head);
        if(nxt==0){
            break;
        }
        // 해당칸에 사과가 있다면 머리를 그 칸에 놓고 끝
        else if(nxt==1){
            x_head=x_head+dx[direc];
            y_head=y_head+dy[direc];
        }
        // 사과 없으면 꼬리 좌표를 없앰
        // 꼬리좌표는 큐로 관리함
        else if(nxt==2){
            x_head=x_head+dx[direc];
            y_head=y_head+dy[direc];
            x_tail=tail.front().first;
            y_tail=tail.front().second;
            tail.pop();
            maps[x_tail][y_tail]=0; // 없앰
        }
        
        
        // 해당 초에서 할 일을 끝내면 방향을 변환시킨다.
        if(direction[T]=='D'){
            direc++;
            if(direc==4)direc=0;
        }
        else if(direction[T]=='L'){
            direc--;
            if(direc==-1)direc=3;
        }
    }
    
    cout<<T;
    return 0;
}
