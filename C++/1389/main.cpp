//
//  main.cpp
//  1389
//
//  Created by 홍승완 on 2023/05/16.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 케빈베이컨수 -> 모든 사람과 케빈 베이컨 게임을 했을 떄 나오는 단계의 합
int n, m;
vector<int> v[102];
int a, b;
int cnt = 0;
void bfs(int a,int b, int visit[102]){
    queue<pair<int, int>> q;
    q.push(make_pair(a,0));
    visit[a] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int cntt = q.front().second;
        q.pop();
 
        if(x == b){
            cnt = cntt;
            break;
        }
 
        for (int i = 0; i < v[x].size(); i++){
            if(!visit[v[x][i]]){
                q.push(make_pair(v[x][i], cntt+1));
                visit[v[x][i]] = 1;
            }
        }
    }
}
 
int main(){
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int result = 1e9;
    int num;
    for (int i = 1; i <= n;i++){
        int temp = 0;
        for (int j = 1; j <= n;j++){
            int visited[102] = {0};
            if(i==j)
                continue;
            bfs(i, j, visited);
            temp += cnt;
            cnt = 0;
        }
        if(result > temp){
            result = temp;
            num = i;
        }
            
    }
    cout << num << '\n';
    return 0;
}

