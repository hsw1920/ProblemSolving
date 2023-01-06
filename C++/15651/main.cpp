//
//  main.cpp
//  15651
//
//  Created by 홍승완 on 2023/01/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
void dfs(int x,vector<int>v) {
    if(x==m){
        for(auto k:v)
            cout<<k<<" ";
        cout<<"\n";
        return;
    }
    
    for(int i=1;i<=n;i++){
        v.push_back(i);
        dfs(x+1,v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    
    vector<int>v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
        dfs(1,v);
        v.pop_back();
    }
    return 0;
}
