#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;


int N, M, C;
int cnt = 0;
int arr[101][101];
bool visit[101][101];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	visit[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (arr[nx][ny] == 0 && !visit[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	vector <int> vec;
	cin >> N >> M >> C;

	for(int i=0;i<C;i++){
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				arr[i][j] = 1;
				visit[i][j] = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				vec.push_back(cnt);
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

	return 0;
}