//
//  main.cpp
//  2042
//
//  Created by 홍승완 on 2023/04/08.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;
ll arr[1000007], tree[1000007];
ll n,m,k;
ll a,b,c;
// m은 수의 변경
// k는 구갓합의 횟수
// a가 1 -> b번째 수를 c로 바꿈
// a가 2 -> b번째 수부터 c번째 수까지 합을 구하기


// O(N)으로 시간초과 -> 펜윅트리로 누적합 갱신
void update(ll i, ll num){
    while(i<=n){
        tree[i]+=num;
        i += (i & -i);
    }
}

ll sum(ll i){
    ll res = 0;
    while(i>0){
        res+=tree[i];
        i -= (i & -i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        update(i,arr[i]);
    }
    while(m+k>0){
        cin>>a>>b>>c;
        if(a==1){ // 변경
            m--;
            // b번째 수를 c로 바꿈
            ll dist=c-arr[b];
            arr[b]=c;
            update(b,dist);

        } else { // 구간합출력
            k--;
            cout<<sum(c)-sum(b-1)<<"\n";
        }
    }
    

    return 0;
}
