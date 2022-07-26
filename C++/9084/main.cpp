//
//  main.cpp
//  9084
//
//  Created by 홍승완 on 2022/04/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        int arr[21];
        // 1 5 10
        int dp[10001]={0,};
        dp[0]=1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>m;
        for(int i=0;i<n;i++){
            for(int j=arr[i];j<=m;j++){
                dp[j]=dp[j]+dp[j-arr[i]];
            }
        }
        cout<<dp[m]<<"\n";
        
    }
    
    return 0;
}
