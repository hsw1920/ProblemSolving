//
//  main.cpp
//  1067-A
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

int op;
int cur=0;
// 북동남서 0123
void turn(int i){
    // 우
    if(i==1){
        cur=(cur+1)%4;
    }else if(i==2){ // 뒤
        cur=(cur+2)%4;
    }else{ // 좌
        cur=(cur+3)%4;
    }
}
int main() {
    init;
    for(int i=0;i<10;i++){
        cin>>op;
        turn(op);
    }
    if(cur==0)cout<<"N";
    else if(cur==1)cout<<"E";
    else if(cur==2)cout<<"S";
    else cout<<"W";
    return 0;
}
