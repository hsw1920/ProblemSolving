//
//  main.cpp
//  16975
//
//  Created by 홍승완 on 2023/04/10.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;

ll n,tmp,m,arr[100001],a,b,c,d, tree[100001];

void update(ll i, ll val){
    while(i<=n){
        tree[i]+=val;
        i+=(i&-i);
    }
}

void rangeUpdate(ll i, ll j, ll diff) {
    update(i, diff);
    update(j+1, -diff);
}

ll sum(ll i){
    ll res = 0;
    while(i>0){
        res+=tree[i];
        i-=(i&-i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        rangeUpdate(i, i, arr[i]);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>tmp;
        if(tmp==1){
            cin>>a>>b>>c; //a~b번째에 c를 더함
            rangeUpdate(a, b, c);
        }
        else {
            cin>>d; // d번째를 출력
            cout<<sum(d)<<"\n";
        }
    }

    return 0;
}
