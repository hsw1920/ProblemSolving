//
//  main.cpp
//  9375
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int tc;
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>tc;
    while(tc--){
        map<string,int>maps;
        cin>>n;
        string a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            maps[b]++;
        }
        int res=1;
        for(auto c :maps){
            res *= (c.second+1);
        }
        res--;
        cout<<res<<"\n";
    }
    return 0;
}
