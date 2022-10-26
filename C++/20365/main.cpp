//
//  main.cpp
//  20365
//
//  Created by 홍승완 on 2022/10/26.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int b=0,r=0;
    int idx=0;
    while(idx<n){
        if(s[idx]=='B'){
            b++;
            while(s[idx]=='B'){
                idx++;
            }
        }
        
        while(s[idx]=='R'){
            idx++;
        }
    }
    idx=0;
    while(idx<n){
        if(s[idx]=='R'){
            r++;
            while(s[idx]=='R'){
                idx++;
            }
        }
        
        while(s[idx]=='B'){
            idx++;
        }
        
    }
    cout<<min(b,r)+1<<"\n";
    
    return 0;
}
