//
//  main.cpp
//  1707
//
//  Created by 홍승완 on 2022/05/13.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<int> vis; // 노드 방문여부 및 색깔

void DFS(int input, int color) {
    vis[input] = color;
    for (int i = 0; i < board[input].size(); i++) {
        if (vis[board[input][i]] == 0) {
            DFS(board[input][i], 3 - color);
        }
    }
}

bool is_disparity() {
    
    for (int i = 0; i < vis.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (vis[i] == vis[board[i][j]]) return false;
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K, V, E; // 케이스 갯수, 정점 갯수, 간선 갯수
    int a, b;
    cin >> K;

    while (K--) {
        cin >> V >> E;

        board.assign(V+1, vector<int>(0,0));// vector 초기화
        vis.assign(V+1, 0);
        
        while (E--) {
            cin >> a >> b;
            board[a].push_back(b);
            board[b].push_back(a);
        } // 그래프 그리기

        for (int i = 1; i < V + 1; i++) {
            if (vis[i] == 0) {
                DFS(i,1);
            }
        } // 컬러 다 입혔다.
        
        if (is_disparity()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
    }
}
