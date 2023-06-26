//
//  main.cpp
//  11051
//
//  Created by 홍승완 on 2023/06/26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
long long dp[1001][1001];

int main() {
    cin>>n>>k;
    //nCr = n-1Cr-1 + n-1Cr
    
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10007;
        }
    }
    cout<<dp[n][k]<<"\n";
    
    return 0;
}
