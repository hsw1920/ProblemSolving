#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int map[101][101];
int visit[101][101] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, h = 0, cnt, res = 1;

void dfs(int x, int y, int height) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (visit[xx][yy] == 0 && map[xx][yy] > height
			&& xx >= 0 && yy >= 0 && xx < n && yy < n) {
			dfs(xx, yy, height);
		}
	}
}

// 그래프갯수가 가장 많도록 하는것
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			h = max(h, map[i][j]);
		}
	}
	for (int q = 1; q <= h; q++) {
		cnt = 0;
		for (int w = 0; w < n; w++)
			memset(visit[w], 0, sizeof(int) * (n+1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0 && map[i][j] > q) {
					dfs(i, j, q);
					cnt++;
				}
			}
		}
		res = max(res, cnt);
	}
	cout << res;
	return 0;
}