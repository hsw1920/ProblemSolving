//
//  main.cpp
//  12904
//
//  Created by 홍승완 on 2022/10/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s,t;
    cin>>s;
    cin>>t;
    int res=0;
    while(1){
        if(s.size()==t.size()){
            if(s==t){
                res=1;
            }
            break;
        }
        else {
            if(t[t.size()-1]=='A'){
                t.pop_back();
            }
            else {
                t.pop_back();
                reverse(t.begin(), t.end());
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}
