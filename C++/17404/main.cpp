//
//  main.cpp
//  17404
//
//  Created by 홍승완 on 2022/03/10.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    int cost[1001][3];
    int ans = 1e9;
    cin>>n;
    int r,g,b;
    for(int i=1;i<=n;i++){
        cin>>r>>g>>b;
        cost[i][0]=r;
        cost[i][1]=g;
        cost[i][2]=b;
    }
    // 이웃한부분을 다르게 -> min으로 해결
    // 1번째와 N번째를 다르게 -> 시작점을 고정해야됨
    for(int start=0; start<3; start++){
        int dp[1001][3];
        for(int j=0;j<=2;j++){
            if(j==start) dp[1][start]=cost[1][start];
            else dp[1][j]= 1e9;
        }
        for(int i=2;i<=n;i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2])+cost[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2])+cost[i][1];
            dp[i][2] = min(dp[i-1][1],dp[i-1][0])+cost[i][2];
        }
        for(int j=0;j<=2;j++){
            if(j==start) continue;
            ans = min(ans, dp[n][j]);
        }
    }
    cout<<ans;
    return 0;
}
