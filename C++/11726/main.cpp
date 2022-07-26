//
//  main.cpp
//  11726
//
//  Created by 홍승완 on 2022/03/15.
//

#include <iostream>
#include <algorithm>
using namespace std;;

int main() {
    int n;
    cin>>n;
    //d[n]=d[n-1]+d[n-2]
    int dp[1001]={0,};
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }
    cout<<dp[n];
    
    return 0;
}



