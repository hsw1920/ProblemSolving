//
//  main.cpp
//  3151
//
//  Created by 홍승완 on 2023/06/03.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int>arr;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    long long res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int target = -(arr[i]+arr[j]);
            int lb=lower_bound(arr.begin()+j+1, arr.end(), target)-arr.begin();
            int ub=upper_bound(arr.begin()+j+1, arr.end(), target)-arr.begin();
            res+=ub-lb;
        }
    }
    
    cout<<res<<"\n";
    return 0;
}
