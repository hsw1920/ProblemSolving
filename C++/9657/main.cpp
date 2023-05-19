//
//  main.cpp
//  9657
//
//  Created by 홍승완 on 2023/05/20.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
 
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    
    for (int i = 5; i <= n; ++i) {
        if (min({ dp[i - 1], dp[i - 3], dp[i - 4] }) == 1) {
            dp[i] = 0;
        } else {
            dp[i] = 1;
        }
    }
    
    if (dp[n] == 1) {
        cout << "SK" << endl;
    } else {
        cout << "CY" << endl;
    }
    
    return 0;
}
