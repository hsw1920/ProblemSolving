//
//  main.cpp
//  16234
//
//  Created by 홍승완 on 2022/07/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,L,R;
int maps[51][51];
int visited[51][51];
int check[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int num=0;
int t=0;
int ch=0;
vector<pair<int,int>>country;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=0;
        }
    }
}
void bfs(int x,int y,int k){
    // 연합나누면서 각 연합의 인구수총합과 나라 수를 체크해주면 좋을듯
    int sum=0;//인구수 누적
    int p=0;//나라수
    queue<pair<int,int>>q;
    visited[x][y]=k;
    q.push({x,y});
    p++;// 나라수 늘려주고
    sum+=maps[x][y];// 인구수누적합
    while(q.size()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            // 인구차이에 적합하면 같은 연합으로 취급
            if(xx>=0&&xx<N&&yy>=0&&yy<N&&visited[xx][yy]==0){
                //인접한 나라의 인구차가 조건에 부합할 때
                if(abs(maps[x][y]-maps[xx][yy])>=L &&abs(maps[x][y]-maps[xx][yy])<=R){
                    visited[xx][yy]=k;
                    p++;// 나라수 늘려주고
                    sum+=maps[xx][yy];// 인구수누적합
                    q.push({xx,yy});
                }
            }
        }
    }
    //나라수와 인구수누적합 pair를 벡터에 넣어줌
    country.push_back({sum,p}); // country의 1번째에 1번연합이 저장됨
}
void distribute(int x, int y){
    int k=visited[x][y];
    int a=country[k].first;
    int b=country[k].second;
    int prev=maps[x][y];
    maps[x][y]=a/b;
    if(prev!=maps[x][y]) ch++; // 다르면 인구이동된것임
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>maps[i][j];
        }
    }
    
    // L~R사이의 인구차이의 집합을 구함 => 연합
    // 연합의 인구수합을 나라의 개수로 나눠서 분배한다. (소수점버림)
    // 반복
    // 연합을 cnt++을 통해서 나타낸다. 초기에는 0
    // 연합을 모두 분류하면 각 연합은 cnt로 표기가됨
    // 같은 연합의 경우 합을 연합의 수로 나누어 분배함
    // 반복한다.
    // 인구이동이 며칠동안 발생하는지 !
    while(1){
        init(); // 연합번호 초기화
        // 연합만들기
        country.clear();// 초기화
        country.push_back({0,0}); //n번째에 n번연합만들기위해
        ch=0;// 인구이동여부체크 -> 그대로 0이면 인구이동 없는것
        num=1; // 연합번호
        // 일단 bfs로 연합번호만 기입해야함
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(visited[i][j]==0){
                    bfs(i,j,num);
                    num++;
                }
            }
        }
        // 연합번호 매겨지고 각 나라수와 인구수합을 country에 다 구해놓았음.
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                // visited에 매겨진 연합번호를 country를 이용해 인구 분배.
                distribute(i,j);
            }
        }
        if(ch==0){ // 인구이동없었으면 끝
            cout<<t<<"\n";
            break;
        }
        t++;
        
    }
    return 0;
}
