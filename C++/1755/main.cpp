//
//  main.cpp
//  1755
//
//  Created by 홍승완 on 2022/10/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n,m;
vector<string>v;
string num[10]={"zero", "one", "two","three","four","five","six","seven","eight","nine"};
int main() {
    cin>>m>>n;
    map<string,int>map;
    for(int i=m;i<=n;i++){
        string tmp,ttmp="";
        tmp=to_string(i);
        for(int j=0;j<tmp.size();j++){
            ttmp+=num[tmp[j]-'0'];
        }
        map[ttmp]=i;
        v.push_back(ttmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<map[v[i]]<<" ";
        
        if(i%10==9)cout<<"\n";
    }
    return 0;
}
