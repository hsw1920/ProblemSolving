//
//  main.cpp
//  1436
//
//  Created by 홍승완 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i=0;
    int x=665;
    cin>>n;
    string tmp;
    while(x++&&i<n){
        tmp=to_string(x);
        if(tmp.find("666") != -1){
            i++;
        }
        if(i==n){
            cout<<x;
            break;
        }
    }
    
    return 0;
}
