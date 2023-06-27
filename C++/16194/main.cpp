//
//  main.cpp
//  16194
//
//  Created by 홍승완 on 2023/06/27.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int p[1001];
int dp[1001];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        dp[i]=p[i];
        if(i==1)continue;
        for(int j=1;j<i;j++){
            dp[i]=min(dp[i],dp[i-j]+p[j]);
        }
    }
    cout<<dp[n]<<"\n";
    
    return 0;
}
