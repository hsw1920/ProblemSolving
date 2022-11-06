//
//  main.cpp
//  15989
//
//  Created by 홍승완 on 2022/11/06.
//

#include <iostream>

using namespace std;

int t,n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>t;
    // 1
    // 1 1 / 2
    // 1 1 1 / 1 2 / 3
    // 1111 / 1 1 2 / 1 3 / 2 2
    while(t--){
        int dp[10001][4];
        cin>>n;
        dp[0][1]=1;
        dp[1][1]=1;
        for(int i=2;i<=n;i++){
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-2][1] + dp[i-2][2];
            if(i>=3){
                dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
            }
        }
        cout<<dp[n][1]+dp[n][2]+dp[n][3]<<"\n";

    }
    return 0;
}
