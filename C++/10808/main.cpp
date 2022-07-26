//
//  main.cpp
//  10808
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
using namespace std;

// 각 알파벳이 단어에 몇 개가 포함되어있는지??
// 해당 알파벳 : 몇개
// key : value
// map, set, 카운팅배열 가능

// 카운팅 배열 사용 -> alphabet[26]

int main() {
    string str;
    cin>>str;
    int alphabet[26]={0,};
    for(int i=0;i<str.size();i++){
        alphabet[str[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        cout<<alphabet[i]<<" ";
    }
    return 0;
}
