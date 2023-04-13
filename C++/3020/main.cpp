//
//  main.cpp
//  3020
//
//  Created by 홍승완 on 2023/04/13.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,h;
int arr[100001] = {0};
int arr2[100001] = {0};
int result = 200001, result_cnt = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>h;
    
    for(int i = 0; i < n/2; i++)
        cin>>arr[i]>>arr2[i];
    
    sort(arr, arr+(n/2));
    sort(arr2, arr2+(n/2));
    
    
    for(int i=1;i<=h;i++) {
        int val = lower_bound(arr,arr+(n/2),i)-arr ;
        val += upper_bound(arr2,arr2+(n/2),h-i)-arr2 ;
        val = n-val;
        
        if (result == val)
            result_cnt++;
        else if (result > val) {
            result = val;
            result_cnt = 1;
        }
    }
    cout<<result<<" "<<result_cnt<<"\n";
    return 0;
}
