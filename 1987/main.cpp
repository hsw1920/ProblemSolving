#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
int dx[4] = {1, -1, 0, 0}; // 남 북 동 서
int dy[4] = {0, 0, 1, -1};
int vis[21][21]={0,};
int visit[26] = {
    0,
};
int res = 0;

string str[21];
void dfs(int x, int y, int cnt)
{
    cnt++;
    res = max(cnt, res);
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < r && yy < c)
        {
            if(vis[xx][yy]==0){
                str[xx][yy];
                if (visit[str[xx][yy] - 'A'] == 0){
                    vis[xx][yy]=1;
                    visit[str[xx][yy] - 'A'] = 1;
                    dfs(xx, yy, cnt);
                    vis[xx][yy]=0;
                    visit[str[xx][yy] - 'A'] = 0;
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++)
    {
        cin >> str[i];
    }
    visit[str[0][0] - 'A'] = 1;
    vis[0][0]=1;
    dfs(0, 0, 0);
    cout << res;
    return 0;
}
