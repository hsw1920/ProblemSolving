//
//  main.cpp
//  9656
//
//  Created by 홍승완 on 2023/06/27.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1001];

int main() {
    int n;
    cin>>n;
    // 0-> SK, 1-> CY
    dp[0]=0;
    dp[1]=1;
    dp[2]=0;
    dp[3]=1;
    for(int i=4;i<=n;i++){
        if(dp[i-1]==1||dp[i-3]==1){
            dp[i]=0;
        }else{
            dp[i]=1;
        }
    }
    if(dp[n]==0)cout<<"SK\n";
    else cout<<"CY\n";
    return 0;
}
