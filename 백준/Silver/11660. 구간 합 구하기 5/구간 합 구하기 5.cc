#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1025][1025];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dp[i][j];
	//상+좌-대각+현재
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1)
				continue;
			//맨 윗줄
			else if (i == 1) {
				dp[i][j] += dp[i][j - 1];
			}
			//맨 왼쪽
			else if (j == 1) {
				dp[i][j] += dp[i - 1][j];
			}
			else {// 나머지
				dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//x1,y1 -> 
		//x1-1,n // n,y1-1 
		//(더하고 뒤에 빼기) x1-1,y1-1

		//x2,y2에서 위에꺼 빼면됨
		int sum = 0, s1, s2=dp[x2][y2];
		if (x1 == 1 && y1 == 1) {
			s1 = 0;
		}
		else if (x1 == 1 && y1 != 1) {
			s1 = dp[x2][y1 - 1];
		}
		else if (x1 != 1 && y1 == 1) {
			s1 = dp[x1 - 1][y2];
		}
		else {
			s1 = dp[x2][y1 - 1] + dp[x1 - 1][y2] - dp[x1 - 1][y1 - 1];
		}
		cout << s2-s1 << "\n";
	}
	return 0;
}
