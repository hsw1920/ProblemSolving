//
//  main.cpp
//  4375
//
//  Created by 홍승완 on 2024/01/04.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    while(cin>>n){
        int res=1;
        int k=1;
        while(1){
            if(res%n==0) break;
            else {
                k++;
                res=res*10+1;
                res%=n;
            }
        }
        cout<<k<<"\n";
    }
    return 0;
}
