//
//  main.cpp
//  1788
//
//  Created by 홍승완 on 2023/07/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin>>n;
    ll dp[1000001];

    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=abs(n);i++)
        dp[i]=(dp[i-1]+dp[i-2])%1000000000;
    
    if(n>0){
        cout<<1<<"\n";
        cout<<dp[n]<<"\n";
    } else if(n==0){
        cout<<0<<"\n";
        cout<<0<<"\n";
    }
    else {
        if(abs(n)%2==0){
            cout<<-1<<"\n";
            cout<<dp[abs(n)]<<"\n";
        }else{
            cout<<1<<"\n";
            cout<<dp[abs(n)]<<"\n";
        }
    }
    
    
    return 0;
}
