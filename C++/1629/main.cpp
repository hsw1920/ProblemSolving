//
//  main.cpp
//  1629
//
//  Created by 홍승완 on 2022/06/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a,b,c;
ll go(ll a, ll b){
    if(b==1) return a%c;
    ll _c = go(a,b/2);
    _c=(_c*_c)%c;
    if(b%2)_c=(_c*a)%c; // 홀수면 한번 더 곱해줌
    return _c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c;
    cout<<go(a,b)<<"\n";
    
    return 0;
}
