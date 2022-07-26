//
//  main.cpp
//  2910
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int n,c,tmp;
vector<pair<int,int>>v;
map<int,int>mp,mp_first;

bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.first==b.first){
        // 빈도수가 같다면 인덱스가 빠른 숫자가 앞으로
        return mp_first[a.second] < mp_first[b.second];
    }
    // 빈도수 큰게 앞으로
    return a.first>b.first;
}

int main() {
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>tmp;
        mp[tmp]++;
        if(mp_first[tmp]==0)mp_first[tmp]=i+1;
    }
    for(auto it: mp){
        v.push_back({it.second,it.first});
    }
    // v에 빈도수, 숫자 pair로 저장됨
    sort(v.begin(),v.end(),cmp);
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].first;j++){
            cout<<v[i].second<<" ";
        }
    }
    
    return 0;
}
