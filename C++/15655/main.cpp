//
//  main.cpp
//  15655
//
//  Created by 홍승완 on 2023/01/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int>v;

void dfs(vector<int>vv, int k){
    if(k==m){
        for(auto u:vv){
            cout<<u<<" ";
        }
        cout<<"\n";
        return;
    }
    int top=vv[k-1];
    for(int i=0;i<n;i++){
        if(top<v[i]){
            vv.push_back(v[i]);
            dfs(vv,k+1);
            vv.pop_back();
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    vector<int>vv;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        vv.push_back(v[i]);
        dfs(vv,1);
        vv.pop_back();
    }
    
    return 0;
}

