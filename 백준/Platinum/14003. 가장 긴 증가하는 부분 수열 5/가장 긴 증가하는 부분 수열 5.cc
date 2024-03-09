//
//  main.cpp
//  14003
//
//  Created by 홍승완 on 2023/06/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int v[1000001];
vector<int>lis;
int dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    int idx=0;
    for(int i=1;i<=n;i++){
        if(lis.size()==0||lis[idx-1]<v[i]){
            lis.push_back(v[i]);
            idx++;
            dp[i]=idx;
        }
        else{
            int targetIdx=lower_bound(lis.begin(), lis.end(), v[i])-lis.begin();
            lis[targetIdx]=v[i];
            dp[i]=targetIdx+1;
        }
    }
    cout<<lis.size()<<"\n";
    vector<int>ans;
    int target = lis.size();
    for(int i=n;i>=1;i--){
        if(dp[i]==target){
            target--;
            ans.push_back(v[i]);
        }
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }

    return 0;
}

//4
//2 0 1 -1
