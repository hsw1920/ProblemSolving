#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include <queue>
#include <map>
using namespace std; // cin,cout 편하게 사용 라이브러리

// memset(maps, 0, sizeof(maps));
// memset 사용시 #include <cstring> 헤더파일 필요함
// fill(v.begin(), v.end(), 1);

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
int c = 0;
int maps[8][8];
int tmp[8][8];

void bfs() {
    //spread : 3개 벽을 세운 뒤 바이러스가 퍼졌을 때의 연구소
    int spread[8][8];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            spread[i][j] = tmp[i][j];

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (spread[i][j] == 2) //바이러스 있으면 큐에 푸시
                q.push(make_pair(i, j));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (spread[nx][ny] == 0) {
                    spread[nx][ny] = 2;  //0이면 2로 바궈서 바이러스 전염되게 함
                    q.push(make_pair(nx, ny)); //바이러스 있으면 큐에 푸시
                }
            }
        }
    }
    //오염되지 않은 부분
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread[i][j] == 0)
                cnt += 1;
        }
    }
    c = max(c, cnt);
}



void wall(int cnt) {
    //벽이 3개 세워졌을 때 bfs, 바이러스 퍼뜨림
    if (cnt == 3) {
        bfs();
        return;
    }
    //벽을 세움
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                wall(cnt + 1);
                //기존의 1을 0으로 바꿔줌
                tmp[i][j] = 0;
            }
        }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
        }
    }
    //벽 세우기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 0) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        tmp[i][j] = maps[i][j];
                    }
                }
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }
    cout << c;
    return 0;
}
