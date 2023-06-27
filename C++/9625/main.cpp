//
//  main.cpp
//  9625
//
//  Created by 홍승완 on 2023/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k;
int main() {
    cin>>k;
    int a,b;
    a=1;b=0;
    for(int i=0;i<k;i++){
        int tmpa=a;
        int tmpb=b;
        b=tmpa+tmpb;
        a=tmpb;
    }
    cout<<a<<" "<<b<<"\n";
    return 0;
}
