//
//  main.cpp
//  25757
//
//  Created by 홍승완 on 2022/10/29.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n; // Y2 F3 O4
char game;
set<string> name;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>game;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        name.insert(tmp);
    }
    if(game=='Y')cout<<name.size()<<"\n";
    else if(game=='F')cout<<name.size()/2<<"\n";
    else if(game=='O')cout<<name.size()/3<<"\n";
    return 0;
}
