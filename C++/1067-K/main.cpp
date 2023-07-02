//
//  main.cpp
//  1067-K
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

int n,t;
vector<int> v;

int main() {
    init;
    cin>>n>>t;
    v.resize(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    
    // 세미나는 연속된 T일
    // i일부터 i+T-1일차까지 계속됨
    // T일 중 하루에는 반드시 특강 1개 존재함
    
    return 0;
}
