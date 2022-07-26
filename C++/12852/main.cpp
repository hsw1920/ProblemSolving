//
//  main.cpp
//  12852
//
//  Created by 홍승완 on 2022/03/15.
//

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    //3나누거나 2나누거나 1빼서 1로만들기 연산최소
    //vector<int>dp[1000001]; 제출할 땐 이게 맞는데 xcode에서 에러남
    vector<int>dp[100001];
    dp[1].push_back(1);
    dp[2]=dp[1];
    dp[2].push_back(2);
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1];
        if(i%2==0)
            if(dp[i/2].size()<dp[i].size())
                dp[i]=dp[i/2];
        if(i%3==0)
            if(dp[i/3].size()<dp[i].size())
                dp[i]=dp[i/3];
        dp[i].push_back(i);
    }

    int k= dp[n].size()-1;
    cout<<k<<"\n";
    for(int i=k;i>=0;i--){
        cout<<dp[n][i]<<" ";
    }
    return 0;
}

