#include <bits/stdc++.h>

using namespace std;

/// 공기 청정기는 항상 1번열에 설치
/// 없는 곳에 미세머지 있음.
/// 1. 미세먼지는 확산되며 동시에 일어남
/// 네 방향으로 확산됨, 칸없으면 확산X
/// 1/5 씩 확산되며 소수점 버림
/// 남은 미세먼지는 A- (1/5)A * 확산된개수
///
/// 2. 공기 청정기 작동함
/// 위쪽은 반시계, 아래쪽은 시계로 순환
/// 바람불면 미세먼지가 바람 방향대로 한칸이동
/// 공기청정기로 들어간 미세먼지는 정화됨
///
/// T초후 방에 남아있는 미세먼지 양을 구하라

int maps[51][51];
bool isEmpty[51][51];
vector<pair<int,int>> aircleaner;
typedef struct {
    int x,y,val;
}Dust;
queue<Dust>v;
int r,c,T;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool isAircleaner(int x, int y){
    for(auto k: aircleaner){
        if(k.first==x && k.second==y) return true;
    }
    return false;
}

void upper(){
    int x=aircleaner[0].first;
    int y=aircleaner[0].second;
    
    for(int i=x-1;i>0;i--){
        maps[i][0]=maps[i-1][0];
    }
    
    for(int i=0;i<c-1;i++){
        maps[0][i]=maps[0][i+1];
    }
    
    for(int i=0;i<x;i++){
        maps[i][c-1]=maps[i+1][c-1];
    }
    
    for(int i=c-1;i>0;i--){
        maps[x][i]=maps[x][i-1];
    }
    
    maps[x][y+1]=0;
}

void lower(){
    int x=aircleaner[1].first;
    int y=aircleaner[1].second;
    
    for(int i=x+1;i<r;i++){
        maps[i][0]=maps[i+1][0];
    }
    
    for(int i=0;i<c;i++){
        maps[r-1][i]=maps[r-1][i+1];
    }
    
    for(int i=r-1;i>x;i--){
        maps[i][c-1]=maps[i-1][c-1];
    }
    
    for(int i=c-1;i>0;i--){
        maps[x][i]=maps[x][i-1];
    }
    
    maps[x][y+1]=0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>r>>c>>T;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maps[i][j];
            if(maps[i][j]==-1){
                aircleaner.push_back({i,j}); //위쪽이 0, 아래가 1번째
            }
            if(maps[i][j]!=-1 && maps[i][j]!=0){
                Dust tmp = {i,j,maps[i][j]};
                v.push(tmp);
            }
        }
    }
    while(T--){
        // 모든 미세먼지 확산
        while(v.size()){
            auto cur = v.front();
            v.pop();
            
            int div=cur.val/5;
            
            for(int i=0;i<4;i++){
                int nx = cur.x+dx[i];
                int ny = cur.y+dy[i];
                
                if(isAircleaner(nx, ny)||nx<0||ny<0||nx>=r||ny>=c) continue;
                
                maps[nx][ny]+=div;
                maps[cur.x][cur.y]-=div;
            }
        }
        // 미세먼지 이동
        
        upper();
        lower();
        
        // 다시 미세먼지 q에 넣어
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(maps[i][j]!=-1 && maps[i][j]!=0){
                    Dust tmp = {i,j,maps[i][j]};
                    v.push(tmp);
                }
            }
        }
    }

    int res=2;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            res+=maps[i][j];
        }
    }
    
    cout<<res<<"\n";
    
    return 0;
}

