//
//  main.cpp
//  1940
//
//  Created by 홍승완 on 2024/01/04.
//

#include <bits/stdc++.h>
using namespace std;
int M,N,val,res;
map<int,int>mp;
int main() {
    res=0;
    cin>>N;
    cin>>M;
    for(int i=0;i<N;i++){
        cin>>val;
        mp[val]=1;
    }
    for(auto k:mp){
        if(k.second==1 && mp[M-k.first]==1){
            res++;
        }
    }
    cout<<res/2<<"\n";
    return 0;
}
