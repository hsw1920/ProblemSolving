//
//  main.cpp
//  1254
//
//  Created by 홍승완 on 2022/10/21.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool isVal(string str){
    int cnt = str.size()/2;
    for(int i=0;i<cnt;i++){
        if(str[i]!=str[str.size()-1-i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string str;
    cin>>str;
    int res=0;
    
    for(int i=0;i<str.size();i++){
        // 앞에서부터 한글자씩 자르기
        string tmp = str.substr(i,str.size()-i);
        if(isVal(tmp)){
            res=str.size()+i;
            break;
        }
    }
    cout<<res<<"\n";
    
    return 0;
}
