//
//  main.cpp
//  2631
//
//  Created by 홍승완 on 2023/07/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int>v;
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int dp[201];
    // 가장 큰 증가하는 부분수열
    // 3 7 5 2 6 1 4
    int res=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
        res=max(dp[i],res);
    }
    
    cout<<n-res<<"\n";
    
    
    return 0;
}
