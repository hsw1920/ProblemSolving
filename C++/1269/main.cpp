//
//  main.cpp
//  1269
//
//  Created by 홍승완 on 2022/11/04.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a,b,tmp;
    cin>>a>>b;
    map<int,int>m;
    for(int i=0;i<a;i++){
        cin>>tmp;
        m[tmp]+=1;
    }
    for(int i=0;i<b;i++){
        cin>>tmp;
        m[tmp]+=2;
    }
    int res=0;
    for(auto k: m){
        if(k.second!=3)res++;
    }
    cout<<res<<"\n";
    return 0;
}
