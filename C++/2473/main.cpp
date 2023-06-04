//
//  main.cpp
//  2473
//
//  Created by 홍승완 on 2023/06/04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n,tmp;
vector<long long>v;
long long ans[3];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    long long res=9e12;
    for(int i=0;i<n-2;i++){
        int l=i+1;
        int r=n-1;
        while(l<r){
            long long val=v[i]+v[l]+v[r];
            if(abs(val)<res){
                res=abs(val);
                ans[0]=v[i];
                ans[1]=v[l];
                ans[2]=v[r];
            }
            if(val<0)l++;
            else r--;
        }
    }
    for(int i=0;i<3;i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
