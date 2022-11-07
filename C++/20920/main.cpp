//
//  main.cpp
//  20920
//
//  Created by 홍승완 on 2022/11/07.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string,int>maps;

bool compare(string a, string b) {
    if (a.size() == b.size() && maps[a] == maps[b]) {
        return a < b;
    }
    else if (maps[a] == maps[b]) {
        return a.size() > b.size();
    }
    return maps[a] > maps[b];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<string>v;
    
    string s;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        if(maps[s]==0&&s.size()>=m){
            v.push_back(s);
        }
        if(s.size()>=m){
            maps[s]++;
        }
        
    }
    sort(v.begin(),v.end(),compare);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
    
    return 0;
}
