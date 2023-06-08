//
//  main.cpp
//  15665
//
//  Created by 홍승완 on 2023/06/08.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n,m;
vector<int>v;
map<string,bool>val;

void dfs(int cur, vector<int> st){

    if(st.size()==m){
        string num="";
        for(auto k: st){
            num+=v[k];
        }
        if(val[num]==0){
            val[num]=1;
            for(auto k: st) cout<<v[k]<<" ";
            cout<<"\n";
        }
        return;
    }
    for(int i=0;i<n;i++){
        st.push_back(i);
        dfs(i,st);
        st.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    vector<int>st;
    for(int i=0;i<n;i++){
        st.push_back(i);
        dfs(i,st);
        st.pop_back();
    }
    
    return 0;
}
