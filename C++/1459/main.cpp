//
//  main.cpp
//  1459
//
//  Created by 홍승완 on 2022/04/25.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    long long x,y,w,s;
    cin>>x>>y>>w>>s;
    long long a = (x+y)*w;
    long long b = min(x,y)*s;
    long long tmp;
    if(abs(x-y)%2==1){
        tmp = (abs(x-y)-1)*s+w;
    }
    else
        tmp =abs(x-y)*s;
    
    b+=min((abs(x-y)*w),tmp);

    cout<<min(a,b);
}
