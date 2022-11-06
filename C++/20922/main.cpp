//
//  main.cpp
//  20922
//
//  Created by 홍승완 on 2022/11/06.
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n,k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    vector<int>v;
    
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int maxLen = 0;
    int s=0, e=1;
    map<int,int>m;
    m[v[s]]++;
    while(e<n){
        m[v[e]]++;
        if(m[v[e]]>k){
            maxLen=max(maxLen,e-s);
            while(m[v[e]]!=k){
                m[v[s]]--;
                s++;
            }
        }
        e++;
    }
    maxLen=max(maxLen,e-s);
    cout<<maxLen<<"\n";
    return 0;
}
