//
//  main.cpp
//  17626
//
//  Created by 홍승완 on 2023/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int dp[50001];
bool powNum[50001];
vector<int>v;

int main() {
    cin>>n;
    for(int i=1;i<=250;i++){
        if(pow(i, 2)<=50000){
            v.push_back(pow(i, 2));
            powNum[(int)pow(i,2)]=true;
        }
    }
    
    fill(dp,dp+50001,1e9);
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(powNum[i])dp[i]=1;
        else{
            for(int j=v.size()-1;j>=0;j--){
                if(i<v[j])continue;
                dp[i]=min(dp[i],dp[i-v[j]]+1);
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
