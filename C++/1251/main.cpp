//
//  main.cpp
//  1251
//
//  Created by 홍승완 on 2022/10/23.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin>>str;
    string res = "";
    for(int i=1;i<str.size()-1;i++){
        for(int j=1;j<str.size()-i;j++){
            string a = str.substr(0,i);
            string b = str.substr(i,j);
            string c = str.substr(i+j);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            if(res=="")res=a+b+c;
            res = min(res, a+b+c);
        }
    }
    cout<<res<<"\n";
    return 0;
}
