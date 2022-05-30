//
//  main.cpp
//  20056
//
//  Created by 홍승완 on 2022/05/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct fireball{
    int x;
    int y;
    int mass;
    int s;
    int d;
};
vector<fireball> maps[51][51];
vector<fireball> fireballs;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;

// 같은 칸에 여러 파이어볼 있을 수 있음
// 이동 후 같은 칸의 파이어볼은 합쳐진다.
// 합쳐지고 4개의 파이어볼로 나눠진다.
// 합쳐진 파이어볼 방향이 모두 홀수거나 모두 짝수면 짝수방향
// 그렇지 않으면 홀수 방향으로 바뀐다.
// 질량은 질량합/5,/// 속력은 속력합/합쳐진개수 이다.
// 질량이 0이되면 없어진다.

void move(){ // 파이어볼 이동
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            maps[i][j].clear();
        }
    }

    for(int i=0; i<fireballs.size(); i++){
        fireball cur = fireballs[i];
        int cx = cur.x, cy = cur.y;
        int nx = cx+dx[cur.d]*cur.s, ny = cy+dy[cur.d]*cur.s;
        while(nx < 1) nx += N; // 주의!! if문 만으로는 안된다
        while(ny < 1) ny += N;
        while(nx > N) nx -= N;
        while(ny > N) ny -= N;
        maps[nx][ny].push_back({nx, ny, cur.mass, cur.s, cur.d});
    }
    return;
}


bool isDir(int x, int y){ // 방향이 모두 홀수인지, 모두 짝수인지 판별하는 함수
    bool evenFlag=false, oddFlag=false;
    for(int i=0; i<maps[x][y].size(); i++){
        if(maps[x][y][i].d % 2) oddFlag = true;
        else evenFlag = true;
    }
    if(evenFlag && !oddFlag) return true;
    else if(!evenFlag && oddFlag) return true;
    else return false;
}

void split(){
    vector<fireball> temp;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int massSum=0, sSum=0;
            if(maps[i][j].size() == 0) continue;
            if(maps[i][j].size() == 1) temp.push_back(maps[i][j][0]); // 1개면 그대로 넣어준다.
            else { // 2개 이상일 경우 쪼갠다.
                for(int k=0; k<maps[i][j].size(); k++) {
                    massSum += maps[i][j][k].mass;
                    sSum += maps[i][j][k].s;
                }
                int nMass = massSum / 5;
                int nS = sSum / maps[i][j].size();
                if(nMass == 0) continue;
                if(isDir(i, j)) {
                    temp.push_back({i, j, nMass, nS, 0});
                    temp.push_back({i, j, nMass, nS, 2});
                    temp.push_back({i, j, nMass, nS, 4});
                    temp.push_back({i, j, nMass, nS, 6});
                } else {
                    temp.push_back({i, j, nMass, nS, 1});
                    temp.push_back({i, j, nMass, nS, 3});
                    temp.push_back({i, j, nMass, nS, 5});
                    temp.push_back({i, j, nMass, nS, 7});
                }
            }
        }
    }
    fireballs = temp; //fireballs 벡터를 tmp벡터로 교체한다.
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    int x, y, mass, d, s, ans=0;
    for(int i=0; i<M; i++){
        cin >> x >> y >> mass >> s >> d;
        fireballs.push_back({x, y, mass, s, d});
    }
    while(K--){
        move();
        split();
    }
    for(int i=0; i<fireballs.size(); i++) ans += fireballs[i].mass;
    cout << ans;
}
