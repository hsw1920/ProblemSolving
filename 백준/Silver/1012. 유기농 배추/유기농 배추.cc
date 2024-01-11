#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include <queue>
#include <cstring>
using namespace std; // cin,cout 편하게 사용 라이브러리
// memset(maps, 0, sizeof(maps));
// fill(v.begin(), v.end(), 1);
int maps[51][51];
bool visited[51][51];
int m, n, k;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool init(int x, int y) {
    return(x >= 0 && y >= 0 && x < m&& y < n);
}

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!visited[nx][ny] && maps[nx][ny] == 1 && init(x, y)==1) {
            dfs(nx, ny);
        }
    }
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cout.tie(0); cout.sync_with_stdio(0);
    int t ,cnt;
    int x, y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(maps, 0, sizeof(maps));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            maps[x][y] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && maps[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt<<"\n";

    }

    return 0;
}