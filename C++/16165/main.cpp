//
//  main.cpp
//  16165
//
//  Created by 홍승완 on 2023/06/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n,m,cnt;
string team,name;
vector<string>v[101];
map<string,int>maps;
map<string,string>findTeam;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>team;
        cin>>cnt;
        vector<string>t;
        for(int j=0;j<cnt;j++){
            cin>>name;
            t.push_back(name);
            findTeam[name]=team;
        }
        sort(t.begin(),t.end());
        v[i]=t;
        maps[team]=i;
        
    }
    int num;
    string q;
    for(int i=0;i<m;i++){
        cin>>q;
        cin>>num;
        if(num==0){
            int targetIdx = maps[q];
            for(auto k: v[targetIdx]){
                cout<<k<<"\n";
            }
        } else {
            cout<<findTeam[q]<<"\n";
        }
    }
    return 0;
}
