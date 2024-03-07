//
//  main.cpp
//  1463
//
//  Created by 홍승완 on 2022/03/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    // 3으로 나누거나 2로나누거나 1을 빼거나 해서 1로만들기
    // 연산횟수의 최솟값
    // bfs or dp
    cin>>N;
    int dp[1000001]={0,};
    //1~N까지의 수
    // dp[1]=0, dp[2]=1, dp[3]=1, dp[4]= min(4이전의 3가지)
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<=N;i++){
        if(i%3==0&&i%2==0){
            dp[i]=min({dp[i/3],dp[i/2],dp[i-1]})+1;
        }
        else if(i%3==0){
            dp[i]=min(dp[i/3],dp[i-1])+1;
        }
        else if(i%2==0){
            dp[i]=min(dp[i/2],dp[i-1])+1;
        }
        else
            dp[i]=dp[i-1]+1;
    }
    cout<<dp[N];
    return 0;
}
