//
//  main.cpp
//  15683
//
//  Created by 홍승완 on 2022/05/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// cctv는 5종류
// 0은 빈칸, 6은 벽, #은 감시영역
// cctv는 서로를 통과할 수 있음
// cctv의 방향을 적절히 정하여 사각지대의 최소 크기를 구하라

// n,m<=8
//      1   2   3   4 번 cctv
// 64 * 4 * 2 * 4 * 4
// 2^13 => 완전탐색 ㅆ가능
int maps[8][8];
int tmp[8][8];
int n,m;
int res=0; // 사각지대 최소 크기
// cctv종류와 xy좌표
vector<pair<int,pair<int,int>>>cctv;
int dx[4]={1,0,-1,0};// 우하좌상
int dy[4]={0,-1,0,1};

//cur방향으로 쭉 감시
void strait1(int x,int y, int cur){
    int xx=x+dx[cur];
    int yy=y+dy[cur];
    while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
        if(tmp[xx][yy]==0)
            tmp[xx][yy]=-1;
        xx=xx+dx[cur];
        yy=yy+dy[cur];
    }
}

void strait2(int x,int y, int cur){
    //상하
    if(cur==0){
        //상
        int xx=x+dx[3];
        int yy=y+dy[3];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[3];
            yy=yy+dy[3];
        }
        //하
        xx=x+dx[1];
        yy=y+dy[1];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[1];
            yy=yy+dy[1];
        }
    }
    //좌우
    else if(cur==1){
        //좌
        int xx=x+dx[2];
        int yy=y+dy[2];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[2];
            yy=yy+dy[2];
        }
        //우
        xx=x+dx[0];
        yy=y+dy[0];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[0];
            yy=yy+dy[0];
        }
    }
}

void strait3(int x,int y, int cur){
    //상우
    if(cur==0){
        //상
        int xx=x+dx[3];
        int yy=y+dy[3];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[3];
            yy=yy+dy[3];
        }
        //우
        xx=x+dx[0];
        yy=y+dy[0];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[0];
            yy=yy+dy[0];
        }
    }
    //우하
    else if(cur==1){
        //우
        int xx=x+dx[0];
        int yy=y+dy[0];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[0];
            yy=yy+dy[0];
        }
        //하
        xx=x+dx[1];
        yy=y+dy[1];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[1];
            yy=yy+dy[1];
        }
    }
    //하좌
    else if(cur==2){
        //하
        int xx=x+dx[1];
        int yy=y+dy[1];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[1];
            yy=yy+dy[1];
        }
        //좌
        xx=x+dx[2];
        yy=y+dy[2];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[2];
            yy=yy+dy[2];
        }
    }
    //좌상
    else if(cur==3){
        //좌
        int xx=x+dx[2];
        int yy=y+dy[2];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[2];
            yy=yy+dy[2];
        }
        //상
        xx=x+dx[3];
        yy=y+dy[3];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[3];
            yy=yy+dy[3];
        }
    }
}

void strait4(int x,int y, int cur){
    //우 빼고
    if(cur==0){
        //상
        int xx=x+dx[3];
        int yy=y+dy[3];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[3];
            yy=yy+dy[3];
        }
        //하
        xx=x+dx[1];
        yy=y+dy[1];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[1];
            yy=yy+dy[1];
        }
        //좌
        xx=x+dx[2];
        yy=y+dy[2];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[2];
            yy=yy+dy[2];
        }
    }
    //하 빼고
    else if(cur==1){
        //우
        int xx=x+dx[0];
        int yy=y+dy[0];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[0];
            yy=yy+dy[0];
        }
        //상
        xx=x+dx[3];
        yy=y+dy[3];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[3];
            yy=yy+dy[3];
        }
        //좌
        xx=x+dx[2];
        yy=y+dy[2];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[2];
            yy=yy+dy[2];
        }
    }
    //좌 빼고
    else if(cur==2){
        //하
        int xx=x+dx[1];
        int yy=y+dy[1];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[1];
            yy=yy+dy[1];
        }
        //우
        xx=x+dx[0];
        yy=y+dy[0];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[0];
            yy=yy+dy[0];
        }
        //상
        xx=x+dx[3];
        yy=y+dy[3];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[3];
            yy=yy+dy[3];
        }
    }
    //상 빼고
    else if(cur==3){
        //좌
        int xx=x+dx[2];
        int yy=y+dy[2];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[2];
            yy=yy+dy[2];
        }
        //우
        xx=x+dx[0];
        yy=y+dy[0];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[0];
            yy=yy+dy[0];
        }
        //하
        xx=x+dx[1];
        yy=y+dy[1];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[1];
            yy=yy+dy[1];
        }
    }
}

void strait5(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        while(xx>=0&&xx<n&&yy>=0&&yy<m&&tmp[xx][yy]!=6){
            if(tmp[xx][yy]==0)
                tmp[xx][yy]=-1;
            xx=xx+dx[i];
            yy=yy+dy[i];
        }
    }
}


void go(int num, int cur, int x, int y){
    if(num==1){
        strait1(x, y, cur);
    }
    else if(num==2){
        strait2(x, y, cur);
    }
    else if(num==3){
        strait3(x, y, cur);
    }
    else if(num==4){
        strait4(x, y, cur);
    }
    else if(num==5){
        strait5(x,y);
    }
}

int cal(stack<int>v){
    //tmp 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j]=maps[i][j];
        }
    }
    // v의 top에는 cctv의 맨 마지막것이 있음
    // v의 size =8이면 cctv[0]은 v[7]
    int k=cctv.size()-1;
    while(!v.empty()){
        int cur=v.top();
        v.pop();
        int num=cctv[k].first;
        int x=cctv[k].second.first;
        int y=cctv[k].second.second;
        k--;
        //cctv의 감시 시뮬레이션
        go(num,cur,x,y);
    }
    int dd=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j]==0)
                dd++;
        }
    }
    return dd;
}

void play(int k,stack<int> v){
    // 종료조건
    if(k==cctv.size()){
        //cctv와 Queue:v에 있는 정보들로 완전탐색.
        res=min(cal(v),res);
        return;
    }
    //1번 cctv일때
    if(cctv[k].first==1){
        for(int i=0;i<4;i++){
            v.push(i);
            play(k+1, v);
            v.pop();
        }
    }
    //2번 cctv일때
    else if(cctv[k].first==2){
        for(int i=0;i<2;i++){
            v.push(i);
            play(k+1, v);
            v.pop();
        }
    }
    //3번 cctv일때
    else if(cctv[k].first==3){
        for(int i=0;i<4;i++){
            v.push(i);
            play(k+1, v);
            v.pop();
        }
    }
    //4번 cctv일때
    else if(cctv[k].first==4){
        for(int i=0;i<4;i++){
            v.push(i);
            play(k+1, v);
            v.pop();
        }
    }
    //5번 cctv일때
    else if(cctv[k].first==5){
        v.push(0);
        play(k+1, v);
        v.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
            if(maps[i][j]>0&&maps[i][j]<6)
                cctv.push_back({maps[i][j],{i,j}});
            if(maps[i][j]==0)
                res++;
        }
    }
    // cctv 8개를 벡터에 담아두었음
    // 8개의 인덱스를 차례로 돌면서 1,2,3,4일때 방향값을 q에 담아둠

    stack<int>v;
    play(0,v);
    cout<<res<<"\n";

    return 0;
}
