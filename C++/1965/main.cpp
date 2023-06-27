//
//  main.cpp
//  1965
//
//  Created by 홍승완 on 2023/06/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int>v;
int dp[1001];
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    
    int res=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    cout<<res<<"\n";
    return 0;
}
