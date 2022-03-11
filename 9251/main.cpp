//
//  main.cpp
//  9251
//
//  Created by 홍승완 on 2022/03/11.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a,b;
    cin>>a>>b;
    int dp[1001][1001]={0,};
    for(int i=1;i<=b.size();i++){
        for(int j=1;j<=a.size();j++){
            if(a[j-1]==b[i-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    cout<<dp[b.size()][a.size()];
    
    return 0;
}
