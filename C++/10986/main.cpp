//
//  main.cpp
//  10986
//
//  Created by 홍승완 on 2023/04/11.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,m,cnt[1001],psum[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    
    ll res=0;
    for(int i=1;i<=n;i++){
        int val;
        cin>>val;
        val%=m;
        if(i==0) psum[i]=val;
        else psum[i]=(psum[i-1]+val)%m;
        if(psum[i]==0)res++;
        cnt[psum[i]]++;
    }
    for(int i=0;i<=m;i++){
        res+=(cnt[i]*(cnt[i]-1))/2; // nC2
    }
    cout<<res<<"\n";
  
    return 0;
}
