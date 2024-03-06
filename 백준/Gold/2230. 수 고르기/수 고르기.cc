//
//  main.cpp
//  2230
//
//  Created by 홍승완 on 2024/03/06.
//

#include <bits/stdc++.h>

using namespace std;

int n,m,val;
vector<int> v;

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }
    
    sort(v.begin(),v.end());

    int st=0,ed=1;
    int res=2e9;
    while (st<=ed && ed<v.size()) {
        if(v[ed]-v[st]>=m){
            res=min(res,v[ed]-v[st]);
            st++;
        } else {
            ed++;
        }
    }
    cout<<res<<"\n";
    return 0;
}
