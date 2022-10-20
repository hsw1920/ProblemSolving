//
//  main.cpp
//  4358
//
//  Created by 홍승완 on 2022/10/20.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    map<string,double>tree;
    string tmp;
    int n=0;
    while(getline(cin,tmp)){
        tree[tmp]++;
        n++;
    }
    cout<<fixed;
    cout.precision(4);
    for(auto k:tree){
        string t = k.first;
        double num=k.second;
        num/=n;
        num*=100;
        cout<<t<<" "<<num<<"\n";
    }
    
    
    return 0;
}
