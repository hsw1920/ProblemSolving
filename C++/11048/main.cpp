//
//  main.cpp
//  11048
//
//  Created by 홍승완 on 2023/06/26.
//

#include <iostream>
#include <algorithm>

using namespace std;

int maps[1001][1001];
int dp[1001][1001];

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>dp[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                if(j==0)continue;
                dp[i][j]+=dp[i][j-1];
            }
            else if(j==0){
                dp[i][j]+=dp[i-1][j];
            }
            else{
                dp[i][j]+= max(max(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
            }
        }
    }
    cout<<dp[n-1][m-1]<<"\n";
    
    return 0;
}
