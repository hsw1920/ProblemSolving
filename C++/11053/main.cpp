//
//  main.cpp
//  11053
//
//  Created by 홍승완 on 2023/06/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>v;
int dp[1001];

// DP
// O(N^2) -> N<=1000 이므로 가능
// N이 1000을 넘는경우?
// -> 시간복잡도 개선을 위해 LIS를 구성할 때 이분탐색(O(log N))을 활용할 수 있음
// LIS -> i번째 인덱스에서 끝나는 "최장 증가 부분수열" 의 길이


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=max(res,dp[i]);
    }
    cout<<res<<"\n";
    return 0;
}
