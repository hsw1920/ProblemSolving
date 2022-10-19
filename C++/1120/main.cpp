//
//  main.cpp
//  1120
//
//  Created by 홍승완 on 2022/10/19.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    //s1이 s2보다 작거나같음.
    // s1->s2에 포함되어있는지?
    string tmp;
    
    // s1이 s2와 길이가 같아질때까지 앞뒤에 추가할 수 있음.
    int d = s2.size()-s1.size();
    
    int minNum=1e9;
    
    for(int i=0;i<=d;i++){
        int cnt =0;
        for(int j=0;j<s1.size();j++){
            if(s1[j]!=s2[i+j]) cnt++;
        }
        minNum=min(minNum,cnt);
    }
    cout<<minNum<<"\n";

    return 0;
}
