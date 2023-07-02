//
//  main.cpp
//  1783
//
//  Created by 홍승완 on 2023/06/30.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,x,y;
int main() {
    int n,m;
    cin>>n>>m;
    if (n==1)
        cout<<1;
    else if (n==2)
        cout<<min(4,(m + 1)/2);
    else if (m<7)
        cout<<min(4,m);
    else
        cout<<m-2<<"\n";
    return 0;
}
