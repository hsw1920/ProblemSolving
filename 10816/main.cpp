//
//  main.cpp
//  10816
//
//  Created by 홍승완 on 2022/05/14.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); //얘네 안해주면 시간초과 억까뜸
    int n,m,k;
    int arr[500001];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>k;
        cout<<(upper_bound(arr,arr+n,k)-lower_bound(arr,arr+n,k))<<" ";
    }
    return 0;
}
