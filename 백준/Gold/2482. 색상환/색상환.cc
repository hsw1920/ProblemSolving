//
//  main.cpp
//  2482
//
//  Created by 홍승완 on 2022/03/31.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin>>n;
    cin>>k;
    int dp[1001][1001];
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        dp[i][1]=i;
    }
    for(int i=4;i<=n;i++){
        for(int j=2;j<=k;j++)
            dp[i][j]=(dp[i-1][j]+dp[i-2][j-1])%1000000003;
    }
    cout<<(dp[n][k])%1000000003;
    return 0;
}

