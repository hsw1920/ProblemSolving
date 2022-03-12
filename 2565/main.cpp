//
//  main.cpp
//  2565
//
//  Created by 홍승완 on 2022/03/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define pint pair<int,int>
using namespace std;

int main() {
    
    int n;
    vector<pint>v;
    v.push_back({0,0});
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int dp[101]={0,};
//    for(auto i:v)
//        cout<<i.first<<"  "<<i.second<<"\n";
    int maxn=0;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(v[i].second > v[j].second){
                if(dp[j]>=dp[i])
                    dp[i]=dp[j]+1;
            }
        }
        maxn=max(maxn,dp[i]);
    }

    cout<<n-maxn;

    return 0;
}
