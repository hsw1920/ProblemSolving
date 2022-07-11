//
//  main.cpp
//  1159
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 성의 첫글자가 같은선수 5명 선발
    // 5명보다 적다면 기권
    // 기권할시 PREDAJA 출력
    // 성은 알파벳 소문자로만
    int n;
    cin>>n;
    string tmp;
    int cnt[26]={0,};
    for(int i=0;i<n;i++){
        cin>>tmp;
        cnt[tmp[0]-'a']++;
    }
    vector<char>v;
    int chk=0;
    for(int i=0;i<26;i++){
        if(cnt[i]>=5){
            v.push_back('a'+i);
            chk=1;
        }
    }
    if(chk==0)
        cout<<"PREDAJA"<<"\n";
    else{
        for(int i=0;i<v.size();i++)
            cout<<v[i];
    }
    
    return 0;
}
