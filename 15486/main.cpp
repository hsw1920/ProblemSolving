//
//  main.cpp
//  15486
//
//  Created by 홍승완 on 2022/03/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int t[1500001]={0,};
    int p[1500001]={0,};
    int dp[1500001]={0,};

    for(int i=1;i<=n;i++){
        cin>>t[i]>>p[i];
    }
    //n부터 시작?
    for(int i=n;i>=1;i--){
        if(i+t[i]-1<=n){
            dp[i]=max(dp[i+1],p[i]+dp[i+t[i]]); // (현재 i일에서 상담을 안하고 i+1일의 dp) or (i일에 상담을하고 i+t[i]일의 값중에 최댓값)을 고른다
        }
        else{
            dp[i]=dp[i+1]; // i일에 상담을 안하면 다음날의 dp를 고려한다.
        }
    }
    cout<<dp[1];
        
    return 0;
}
