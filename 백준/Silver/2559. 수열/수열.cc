//
//  main.cpp
//  2559
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,k; //n일, k일 연속
int arr[100001];
int dp[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    dp[0]=arr[0];
    for(int i=1;i<k;i++){
        dp[i]=dp[i-1]+arr[i];
    }
    int max_num=dp[k-1];
    for(int i=k;i<n;i++){
        dp[i]=dp[i-1]-arr[i-k]+arr[i];
        max_num=max(max_num,dp[i]);
    }
    cout<<max_num<<"\n";
    return 0;
}
