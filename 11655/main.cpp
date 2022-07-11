//
//  main.cpp
//  11655
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // ROT13 => 암호화 , 아스키로 알파벳만 13만큼 순환
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z'){
            if(s[i]+13>'z')s[i]=s[i]+13-26;
            else s[i]+=13;
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            if(s[i]+13>'Z')s[i]=s[i]+13-26;
            else s[i]+=13;
        }
        cout<< s[i];
    }
    return 0;
}
