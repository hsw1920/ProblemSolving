//
//  main.cpp
//  1940
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,arr[150001],cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    if(m>200000) cout<<0<<"\n";
    else{
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==m)cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
