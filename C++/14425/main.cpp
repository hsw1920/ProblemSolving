//
//  main.cpp
//  14425
//
//  Created by 홍승완 on 2022/10/18.
//

#include <iostream>
#include <map>

using namespace std;

int n,m;
map<string,int>str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        str[tmp]=1;
    }
    int res=0;
    for(int i=0;i<m;i++){
        string tmp;
        cin>>tmp;
        if(str[tmp]==1) res++;
    }
    cout<<res<<"\n";
    
    return 0;
}
