//
//  main.cpp
//  1562
//
//  Created by 홍승완 on 2022/04/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[1<<10][101][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    if (n <= 9) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= 9; i++) {
        dp[1<<i][1][i] = 1;
    }
    //(int)10e8;
    for (int i = 2; i <= n; i++) { // i는 숫자 갯수
        for (int k = 0; k <= 9; k++) { // k는 마지막 숫자 번호
            for (int bit = 0; bit < (1 << 10); bit++) { // bit는 이전 비트
                if (k == 0) {
                    dp[bit | (1 << k)][i][k] += dp[bit][i - 1][k+1] % (int)10e8;
                }
                else if (k == 9) {
                    dp[bit | (1 << k)][i][k] += dp[bit][i - 1][k - 1] % (int)10e8;
                }
                else {
                    dp[bit | (1 << k)][i][k] += (dp[bit][i - 1][k + 1] + dp[bit][i - 1][k - 1]) % (int)10e8;
                }
            }
        }
    }

    long long res = 0;

    for (int i = 0; i <= 9; i++) {
        res = (res + dp[(1<<10) - 1][n][i]) % (int)10e8;
    }

    cout << res;
    return 0;
    
}
