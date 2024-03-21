#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int n=sticker.size();
    int dp[100001][2][2]; // idx | 선택X, 선택O | 0번 선택X, 선택O
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    dp[0][1][0]=0;
    dp[0][1][1]=sticker[0];
    
    dp[1][0][0]=0;
    dp[1][0][1]=sticker[0];
    dp[1][1][0]=sticker[1];
    dp[1][1][1]=0;

    if(sticker.size() == 1){
        return sticker[0];
    }
    else if(sticker.size() == 2){
        return max(sticker[0],sticker[1]);    
    }
    
    
    
    for(int i=2;i<n;i++){
        dp[i][0][0]=max(max(dp[i-1][1][0],dp[i-2][1][0]), 
                        max(dp[i-1][0][0],dp[i-2][0][0])); 
        dp[i][0][1]=max(max(dp[i-1][1][1],dp[i-2][1][1]), 
                        max(dp[i-1][0][1],dp[i-2][0][1])); 
        dp[i][1][0]=max(max(dp[i-1][0][0],dp[i-2][1][0]),dp[i-2][0][0]) + sticker[i];
        dp[i][1][1]=max(max(dp[i-1][0][1],dp[i-2][1][1]),dp[i-2][0][1]) + sticker[i];
    }
    
    answer = max(max(dp[n-1][0][0],dp[n-1][0][1]),dp[n-1][1][0]);
    
    return answer;
}