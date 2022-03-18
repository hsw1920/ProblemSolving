//
//  main.cpp
//  2638
//
//  Created by 홍승완 on 2022/03/18.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, ans;
int maps[100][100];
bool visited[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool melt() {
    bool melted = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maps[i][j] >= 3) {
                maps[i][j] = 0;
                melted = true;
            } else if (maps[i][j] == 2) maps[i][j] = 1;
        }
    }
    return melted;
}

void bfs() {
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny])
                continue;
            if (maps[nx][ny] >= 1) {
                maps[nx][ny] += 1;
                continue;
            }
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>maps[i][j];
        }
    }
    
    while(1) {
        bfs();
        if (melt()) ans++;
        else break;
    }
    
    cout<<ans<<"\n";
    return 0;
}
