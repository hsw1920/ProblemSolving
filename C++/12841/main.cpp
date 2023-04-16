//
//  main.cpp
//  12841
//
//  Created by 홍승완 on 2023/04/16.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<long long>cross(100001,0);
vector<long long>ld(100001,0);
vector<long long>rd(100001,0);
vector<long long>dp(100001,0);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cross[i];
    }
    for(int i=2;i<=n;i++){
        cin>>ld[i];
        ld[i]+=ld[i-1];
    }
    for(int i=2;i<=n;i++){
        cin>>rd[i];
        rd[i]+=rd[i-1];
    }
    
    for(int i=1;i<=n;i++){
        dp[i]=ld[i]+cross[i]+(rd[n]-rd[i]);
    }
    long long res=dp[1], resn=1;
    for(int i=2;i<=n;i++){
        if(res>dp[i]){
            resn=i;
            res=dp[i];
        }
    }
    cout<<resn<<" "<<res<<"\n";
    
    return 0;
}
