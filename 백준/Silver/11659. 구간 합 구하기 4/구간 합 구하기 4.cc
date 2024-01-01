//
//  main.cpp
//  11659
//
//  Created by 홍승완 on 2022/03/15.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,a,b;
    
    cin>>n>>m;
    int num;
    int dp[100001]={0,};
    for(int j=1;j<=n;j++){
        cin>>num;
        dp[j]+=dp[j-1]+num;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<dp[b]-dp[a-1]<<"\n";
    }
    return 0;
}
