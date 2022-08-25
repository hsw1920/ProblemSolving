//
//  main.cpp
//  14405
//
//  Created by 홍승완 on 2022/08/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s[3]={"pi","ka","chu"};
    string str;
    cin>>str;
    int len=str.size();
    int idx=0;
    while(idx<len){
        int ccc=0;
        for(int i=0;i<3;i++){
            int k=s[i].size();
            int chk=0;
            for(int j=0;j<k;j++){
                if(s[i][j]!=str[idx+j]){
                    chk=1;
                    break;
                }
            }
            if(chk==0){
                idx+=k;
                ccc=1;
                break;
            }
        }
        if(ccc==0){
            cout<<"NO\n";
            return 0;
        }
    }
    
    cout<<"YES\n";
    
    return 0;
}
