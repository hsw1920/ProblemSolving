//
//  main.cpp
//  12015
//
//  Created by 홍승완 on 2022/04/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int arr[1000001];
    int dp[1000001]={0,};
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[i]=1e9;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //arr[i]보다 크거나 같은수중 처음 인덱스를 찾는다
        int idx=lower_bound(dp, dp+i, arr[i])-(dp);
        // 해당인덱스를 arr[i]로 변경
        // => i번째 인덱스는 dp[i]일때 i개의 연속된 수열중
        // =>dp[i]값이 가장 크다는 뜻
        dp[idx]=arr[i];
    }
    // 초기화된 값이 아닌 값중 인덱스가 가장 큰 값이
    // 가장 긴 수열의 길이이다.
    cout<<lower_bound(dp, dp+n, 1e9)-dp;
    
    return 0;
}
