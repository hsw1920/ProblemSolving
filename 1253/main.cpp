//
//  main.cpp
//  1253
//
//  Created by 홍승완 on 2022/05/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[2001];
vector<long long>good;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int res=0;
    for(int i=0;i<n;i++){
        int tmp=arr[i];
        int l=0,r=n-1,sum;
        while(l<r){
            sum=arr[l]+arr[r];
            if(sum==tmp){
                if(l!=i&&r!=i){
                    res++;
                    break;
                }
                else if(l==i)l++;
                else if(r==i)r--;
            }
            else if(sum<tmp)l++;
            else r--;
        }
    }
    cout<<res;
    return 0;
}
