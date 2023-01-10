//
//  main.cpp
//  15657
//
//  Created by 홍승완 on 2023/01/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int>v;

void dfs(vector<int>num,int k){
    if(k==m){
        for(auto u:num){cout<<u<<" ";}
        cout<<"\n";
        return;
    }
    int top=num[k-1];
    
    for(int i=0;i<n;i++){
        if(v[i]<top)continue;
        num.push_back(v[i]);
        dfs(num,k+1);
        num.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    vector<int>vv;
    for(int i=0;i<n;i++){
        vv.push_back(v[i]);
        dfs(vv,1);
        vv.pop_back();
    }
    
    return 0;
}

