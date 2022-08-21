//
//  main.cpp
//  1094
//
//  Created by 홍승완 on 2022/08/21.
//

#include <iostream>

using namespace std;

int n,k=1;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    while(n!=1){
        if(n&1)k++;
        n/=2;
    }
    cout<<k<<"\n";
    return 0;
}
