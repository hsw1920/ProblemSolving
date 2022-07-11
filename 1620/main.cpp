//
//  main.cpp
//  1620
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    map<string,int>m1;
    map<int,string>m2;
    for(int i=0;i<n;i++){
        cin>>s;
        m1.insert({s,i+1});
        m2.insert({i+1,s});
    }
    for(int i=0;i<m;i++){
        cin>>s;
        //
        if(atoi(s.c_str())==0){
            cout<<m1[s]<<"\n";
        }
        else{
            cout<<m2[atoi(s.c_str())]<<"\n";
        }
    }
    return 0;
}
