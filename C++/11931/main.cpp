//
//  main.cpp
//  11931
//
//  Created by 홍승완 on 2023/05/18.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++){cin>>k;v.push_back(k);}
    sort(v.begin(),v.end(),greater<int>());
    for(auto k:v)cout<<k<<"\n";
    return 0;
}
