//
//  main.cpp
//  3036
//
//  Created by 홍승완 on 2022/08/29.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int n,k,a,b,x;
int arr[101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>k;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        if(k>arr[i]){
            x=gcd(k,arr[i]);
        }
        else{
            x=gcd(arr[i],k);
        }
        cout<<k/x <<"/"<<arr[i]/x<<"\n";
    }
    return 0;
}
