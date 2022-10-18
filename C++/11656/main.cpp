//
//  main.cpp
//  11656
//
//  Created by 홍승완 on 2022/10/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;
string str;
vector<string>v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>str;
    for(int i=0;i<str.size();i++){
        string tmp = str.substr(i,str.size());
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(auto i: v) cout<<i<<"\n";
    return 0;
}
