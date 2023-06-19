//
//  main.cpp
//  11722
//
//  Created by 홍승완 on 2023/06/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>v;
int dp[1001];

// n<=1000 -> O(N^2) 가능
// -> LIS -> DP

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        v.push_back(tmp);
    }
    int res=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[i]<v[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(dp[i],res);
    }
    
    cout<<res<<"\n";
    
    return 0;
}
