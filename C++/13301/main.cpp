//
//  main.cpp
//  13301
//
//  Created by 홍승완 on 2023/06/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long dp[81];
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    if(n==1)cout<<4<<"\n";
    else if(n==2)cout<<6<<"\n";
    else if(n==3)cout<<10<<"\n";
    else{
        cout<<dp[n]*3+dp[n-1]*2+dp[n-2]*2+dp[n-3]<<"\n";
    }
    return 0;
}
