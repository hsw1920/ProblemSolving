#include <bits/stdc++.h>

using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        dp[i][0]=dp[i-1][0]+triangle[i][0];
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
        }
    }
    int h = triangle.size()-1;
    answer = *max_element(dp[h],dp[h]+h);
    return answer;
}