//
//  main.cpp
//  2302
//
//  Created by 홍승완 on 2022/04/23.
//

#include <iostream>

using namespace std;

int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int dp[41];
    cin >> n >> m;
    
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for (int i = 3; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int idx = 1;
    int res = 1;
    int t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        res *= dp[t - idx];
        idx = t + 1;
    }
    res *= dp[n+1 - idx];
    
    cout << res;
    return 0;
}
