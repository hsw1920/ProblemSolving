//
//  main.cpp
//  10610
//
//  Created by 홍승완 on 2022/10/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

string n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    sort(n.begin(),n.end(),greater<int>());
    int k=0;
    if(n[n.size()-1]!='0'){cout<<-1<<"\n";return 0;}
    
    for(auto i: n){
        k+=i-'0';
    }
    if(k%3==0)cout<<n<<"\n";
    else cout<<-1<<"\n";
    
    return 0;
}

//30 60 120 150 180 210 240 270 300 330 360 390 420 450 ... 900 930 960 990 1020
