//
//  main.cpp
//  15988
//
//  Created by 홍승완 on 2023/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t,n;
long long dp[1000001];
int main() {
    cin>>t;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    int prv=4;
    while(t--){
        cin>>n;
        if(prv<=n){
            for(int i=prv;i<=n;i++){
                dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
            }
            prv=n;
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}
