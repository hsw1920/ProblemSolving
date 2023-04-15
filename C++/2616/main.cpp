//
//  main.cpp
//  2616
//
//  Created by 홍승완 on 2023/04/15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int>v(50001,0),psum(50001,0);
int dp[4][50001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        psum[i]=psum[i-1]+v[i];
    }
    cin>>m;
    for(int i=1;i<=3;i++){
        for(int j=i*m;j<=n;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+(psum[j]-psum[j-m]));
        }
    }
    cout<<dp[3][n]<<"\n";
    return 0;
}
