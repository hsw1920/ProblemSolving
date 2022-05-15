//
//  main.cpp
//  1822
//
//  Created by 홍승완 on 2022/05/15.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int a[500001],b[500001];
vector<int> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(b,b+m);
    for(int i=0;i<n;i++){
        if(!binary_search(b,b+m,a[i])){
            v.push_back(a[i]);
        }
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    
    return 0;
}
