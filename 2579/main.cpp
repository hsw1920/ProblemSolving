//
//  main.cpp
//  2579
//
//  Created by 홍승완 on 2022/03/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,s[301];
    cin>>n;
    // 계딴은 1,2씩, 연속3계단 ㄴㄴ, 마지막 계단반드시 밟기
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int dp[301][3]={0,};
    //현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때
    // 점수합의 최댓값, 단 i번째 계단은 반드시 밟아야함
    //ex)dp[k][1] k번째계단인데 현재까지 연속 1개밟은것
    // dp[k][1]=max(dp[k-2][1],dp[k-2][2])+S[k]
    // dp[k][2]=dp[k-1][1]+S[k]
    dp[1][1]=s[1];
    dp[1][2]=0;
    dp[2][1]=s[2];
    dp[2][2]=s[1]+s[2];
    for(int i=3;i<=n;i++){
        dp[i][1]=max(dp[i-2][2],dp[i-2][1])+s[i];
        dp[i][2]=dp[i-1][1]+s[i];
    }
    cout<<max(dp[n][1],dp[n][2]);
    return 0;
}
