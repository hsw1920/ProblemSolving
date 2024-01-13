//
//  main.cpp
//  3474
//
//  Created by 홍승완 on 2024/01/13.
//

#include <bits/stdc++.h>
using namespace std;
int t,n,two,five;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>t;
    while(t--){
        two=0;five=0;
        cin>>n;
        //2*5의 개수
        for(int i=2;i<=n;i*=2){
            two+=n/i;
        }
        for(int i=5;i<=n;i*=5){
            five+=n/i;
        }
        cout<<min(two,five)<<"\n";
    }
    return 0;
}
