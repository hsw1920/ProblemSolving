//
//  main.cpp
//  11055
//
//  Created by 홍승완 on 2022/03/16.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int a[1001]={0,};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int dp[1000][2]={0,};
    dp[1][0]=a[1];
    dp[1][1]=a[1];
    for(int i=2;i<=n;i++){
        int maxSum=0;
        for(int j=i-1;j>=1;j--){
            if(dp[j][1]<a[i] && dp[j][0]>maxSum){
                maxSum=dp[j][0];
            }
        }
        dp[i][0]=maxSum+a[i];
        dp[i][1]=a[i];
    }
    int k=0;
    for(int i=1;i<=n;i++){
        k=max(dp[i][0],k);
    }
    cout<<k;
    //  1 2    3   4    5    6  7
    //1 1 101  3   53   113
    //2
    //3
    //4
    return 0;
}
