//
//  main.cpp
//  14490
//
//  Created by 홍승완 on 2022/10/23.
//

#include <iostream>
#include <numeric>
using namespace std;
int gcd(int n, int m){
    if(m==0)return n;
    else {
        return gcd(m,n%m);
    }
}
int lcm(int n,int m){
    return (n*m)/gcd(n,m);
}
int main() {
    string str;
    cin>>str;
    int idx = str.find(":");
    int a = stoi(str.substr(0,idx));
    int b = stoi(str.substr(idx+1,str.size()-idx));
    
    auto k = gcd(a, b);
    cout<<a/k<<":"<<b/k<<"\n";
    return 0;
}
