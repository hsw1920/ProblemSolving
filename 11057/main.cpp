//
//  main.cpp
//  11057
//
//  Created by 홍승완 on 2022/03/13.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dp[1001][10] = {0,};
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {

        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][0] = 1;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
            dp[i][j] %= 10007;
        }
    }

    int res = 0;
    for (int i = 0; i < 10; i++)
        res = (res + dp[n][i]);

    cout << res % 10007;

    return 0;
}
