//
//  main.cpp
//  14002
//
//  Created by 홍승완 on 2023/06/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int dp[1001];
int prevs[1001];
vector<int>v;

// N<=1000 -> O(N^2)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    fill(prevs,prevs+n,1e9);
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        v.push_back(tmp);
    }
    int res=0;
    int idx=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){ // j -> 20
                dp[i]=max(dp[j]+1,dp[i]);
                if(prevs[j]!=1e9){
                    if(v[prevs[i]]<v[j])
                        prevs[i]=j;
                }
                else if(prevs[i]==1e9){
                    prevs[i]=j;
                }
                else {
                    if(v[prevs[i]]<v[j]){
                        prevs[i]=j;
                    }
                }
                
            }
        }
        if(res<dp[i]){
            res=dp[i];
            idx=i;
        }
    }
    vector<int>arr;
    int target=res;
    for(int i=idx;i>=0;i--){
        if(target==dp[i] && target>0){
            arr.push_back(v[i]);
            target--;
        }
    }
    
    sort(arr.begin(),arr.end());
    
    cout<<res<<"\n";
    for(auto k: arr){
        cout<<k<<" ";
    }
    
    
    return 0;
}
