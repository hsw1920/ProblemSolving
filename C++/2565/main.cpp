//
//  main.cpp
//  2565
//
//  Created by 홍승완 on 2022/03/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,dp[101],arr[101];
vector<pair<int,int>>v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    int res=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[i].second>v[j].second){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    
    cout<<n-res<<"\n";
    
    return 0;
}
