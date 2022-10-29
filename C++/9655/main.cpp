//
//  main.cpp
//  9655
//
//  Created by 홍승완 on 2022/10/29.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    dp[1]=0;
    dp[2]=1;
    dp[3]=0;
    
    for(int i=4;i<=n;i++){
        if(dp[i-1]==0 || dp[i-3]==0) dp[i]=1;
        else dp[i]=0;
    }
    if(dp[n]==0) cout<<"SK"<<"\n";
    else cout<<"CY"<<"\n";
    
    return 0;
}
