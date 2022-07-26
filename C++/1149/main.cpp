//
//  main.cpp
//  1149
//
//  Created by 홍승완 on 2022/03/15.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int h[1001][3]={0,};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i][0]>>h[i][1]>>h[i][2];
    }
    int dp[1001][3];
    dp[1][0]=h[1][0];
    dp[1][1]=h[1][1];
    dp[1][2]=h[1][2];
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+h[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+h[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+h[i][2];
    }
    cout<<min({dp[n][0],dp[n][1],dp[n][2]});
    
    
    return 0;
}
