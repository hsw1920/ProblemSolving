//
//  main.cpp
//  9095
//
//  Created by 홍승완 on 2022/03/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,T;
    cin>>T;
    //각 테케마다 n(<11)을 1,2,3의 합으로 나타내는 방법의 수
    for(int i=0;i<T;i++){
        cin>>n;
        int dp[11]={0,};
        dp[1]=1;
        //dp[2] = 1+1, 2
        //dp[3] = (1+1+1, 2+1) (1+2) 3
        // -> dp[1]에 더한거 dp[2]에 더한거 dp[3]그냥
        dp[2]=2;dp[3]=4;
        for(int j=4;j<=n;j++){
            dp[j]=dp[j-3]+dp[j-2]+dp[j-1];
        }
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}
