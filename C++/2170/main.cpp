//
//  main.cpp
//  2170
//
//  Created by 홍승완 on 2023/05/05.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,x,y;
vector<pair<int,int>>v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(x>y)v.push_back({y,x});
        else v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    int st=v[0].first;
    int ed=v[0].second;
    int ans=0;
    for(int i=1;i<n;i++){
        if(ed>v[i].first){
            if(v[i].second>ed) ed=v[i].second;
        }
        else {
            ans+=ed-st;
            st=v[i].first;
            ed=v[i].second;
        }
    }
    ans+=ed-st;
    cout<<ans<<"\n";
    return 0;
}
