//
//  main.cpp
//  1969
//
//  Created by 홍승완 on 2022/10/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n,m; // <=1000, <=50

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<string>v;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int res=0;
    string resString="";
    for(int i=0;i<m;i++){
        map<char,int>c;
        // 각 자리에서 최빈문자의 개수 판단
        for(int j=0;j<n;j++){
            c[v[j][i]]++;
        }
        int tmp=0;
        char pushCh='T'; // resString에 넣을 문자
        for(auto k:c){
            if(tmp<k.second){
                tmp=k.second;
            }
        }
        for(auto k:c){
            if(tmp==k.second && pushCh>=k.first)
                pushCh = k.first;
        }
        // pushCh 넣기
        resString+=pushCh;
        // 최빈문자가 아닌것들 개수
        res += (n-tmp);
//        cout<<res<<" : "<<i<<"\n";
    }
    
    cout<<resString<<"\n";
    cout<<res<<"\n";
     
    return 0;
}
