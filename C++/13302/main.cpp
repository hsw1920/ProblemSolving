//
//  main.cpp
//  13302
//
//  Created by 홍승완 on 2023/04/22.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1, 10000, x
// 3, 25000, 1
// 5, 37000, 2
// 쿠폰 3장이 하루

int n,m;
int set[101];
int dp[101][101];

int dfs(int cur, int coupon){
    if(cur>n)return 0;
    if(dp[cur][coupon]!=1e9) return dp[cur][coupon];
    if(set[cur]) return dp[cur][coupon] = dfs(cur+1, coupon);
    int &res = dp[cur][coupon];
    res = min(res,dfs(cur+1,coupon)+10000);
    res = min(res,dfs(cur+3,coupon+1)+25000);
    res = min(res,dfs(cur+5,coupon+2)+37000);
    if(coupon>=3)res=min(res, dfs(cur+1, coupon-3));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        set[tmp]=1;
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++)
            dp[i][j]=1e9;
    }
    cout<<dfs(1,0)<<"\n";
    
    return 0;
}
