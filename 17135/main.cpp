//
//  main.cpp
//  17135
//
//  Created by 홍승완 on 2022/05/07.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n,m,d;
int arr[16][16];
int temp[16][16];
bool visit[16][16];
int dx[3] = {0,-1,0};
int dy[3] = {-1,0,1};
vector<int> seq;

struct node {
    int x, y, num;
};

int BFS() {
    int cnt=0;
    queue<pair<int ,int> > tmp;
    for(int i=0 ; i<m ; i++) {
        if(seq[i] == 1) {
            if(temp[n-1][i] == 1) {
                tmp.push(make_pair(n-1, i));
                continue;
            }
            memset(visit, false, sizeof(visit));
            queue<node> q;
            node p = {n-1, i, 1};
            q.push(p);
            visit[n-1][i] = true;

            while(!q.empty()) {
                int x = q.front().x;
                int y = q.front().y;
                int num = q.front().num;
                q.pop();
                if(num>d) continue;

                if(temp[x][y] == 1) {
                    tmp.push(make_pair(x, y));
                    break;
                }

                for(int j=0 ; j<3 ; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if(x<0 || x>=n || y<0 || y>=m) continue;
                    if(!visit[nx][ny]) {
                        node np = {nx, ny, num+1};
                        q.push(np);
                        visit[nx][ny] = true;
                    }
                }
            }
        }
    }

    while(!tmp.empty()) {
        int x = tmp.front().first;
        int y = tmp.front().second;
        tmp.pop();
        if(temp[x][y] == 1) {
            cnt++;
            temp[x][y] = 0;
        }
    }

    return cnt;
}

bool search() {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(temp[i][j] == 1) return true;
        }
    }

    return false;
}

void next() {
    for(int i= m-1 ; i>=0 ; i--) {
        for(int j=n-1 ; j>=0 ; j--) {
            if(j==n-1) {
                temp[j][i] = 0;
            } else {
                if(temp[j][i] == 1) {
                    temp[j][i] = 0;
                    temp[j+1][i] = 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=0 ; i<m-3 ; i++) {
        seq.push_back(0);
    }
    for(int i=0 ; i<3 ; i++) {
        seq.push_back(1);
    }
    
    int ans=0;
    do{
        for(int i=0 ; i<n ; i++) { // arr배열은 망가지면 안되므로 temp배열에 복사해서 탐색
            for(int j=0 ; j<m ; j++) {
                temp[i][j] = arr[i][j];
            }
        }

        int num=0;
        while(search()) { // 1이 남아있다면
            num += BFS(); // 탐색하면서 적을 제거하고
            next(); // 적이 이동한다.
        }
        if(ans<num) {
            ans = num;
        }
    }while(next_permutation(seq.begin(), seq.end()));

    cout << ans;

    return 0;
}
