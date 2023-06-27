//
//  main.cpp
//  14916
//
//  Created by 홍승완 on 2023/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int dp[100001];
    cin>>n;
    // 2원이랑 5원으로만 거스름돈
    dp[1]=-1;
    dp[2]=1;
    dp[3]=-1;
    dp[4]=2;
    dp[5]=1;
    dp[6]=-1;
    dp[7]=2;
    for(int i=6;i<=n;i++){
        if(dp[i-2]!=-1&&dp[i-5]!=-1){
            dp[i]=min(dp[i-2],dp[i-5])+1;
        }else if(dp[i-2]!=-1&&dp[i-5]==-1){
            dp[i]=dp[i-2]+1;
        }else if(dp[i-2]==-1&&dp[i-5]!=-1){
            dp[i]=dp[i-5]+1;
        }else{
            dp[i]=-1;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
