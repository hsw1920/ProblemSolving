//
//  main.cpp
//  1067-I
//
//  Created by 홍승완 on 2023/07/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <tuple>
#include <map>
#include <iomanip>
#include <numeric>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;
typedef tuple<int,int,int> iii;
typedef pair<ll, ll> pll;

ll n,k;
vector<ll>v;

// 충전
// 소모
// 번호차의 k곱한만큼 배터리에서 소모
ll maxRes=-1e18;
ll up(int i){
    return v[i];
}
ll down1(int i){
    return -v[i];
}
ll down2(int i, int j){
    return -(j-i)*k;
}
int main() {
    init;
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    // 충전을 최대로 하는경우
    int s=0;
    int e=1;
    
    while(s<e){
        if(v[s]<v[e+1]){
            s=e+1;
            e=e+2;
            continue;
        }
        ll cur=up(s)+down1(e)+down2(s,e);
        ll cur2=up(e)+down1(s)+down2(s,e);
        
        if(maxRes<cur){
            maxRes=cur;
        }
        if(maxRes<cur2){
            maxRes=cur2;
        }
        if(e<n-1)e++;
        else s++;
    }
    
    // 소모를 최대로 하는경우
   
    cout<<maxRes<<"\n";
    return 0;
}
