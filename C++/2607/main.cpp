//
//  main.cpp
//  2607
//
//  Created by 홍승완 on 2022/10/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<string>v;
int chk[100][26];
int main() {
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
        for(int j=0;j<s.size();j++){
            chk[i][s[j]-'A']++;
        }
    }
    
    int res=0;
    for(int i=1;i<n;i++){
        int k=0;
        
        for(int j=0;j<26;j++){
            k+=abs(chk[0][j]-chk[i][j]);
        }
        
        // 사이즈가 같을 때
        if(v[0].size()==v[i].size()) {
            if(k<=2) res++;
        }
        // 다를 때
        else {
            if(k<=1) res++;
        }
    }
    
    cout<<res<<"\n";
    
    return 0;
}
