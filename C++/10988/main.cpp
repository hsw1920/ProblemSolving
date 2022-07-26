//
//  main.cpp
//  10988
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
    
    string str1;
    string str2;
    cin>>str1;
    str2=str1;
    reverse(str1.begin(),str1.end());
    if(str1==str2){
        cout<<1<<"\n";
    }
    else{
        cout<<0<<"\n";
    }
    return 0;
}
