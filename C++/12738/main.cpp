//
//  main.cpp
//  12738
//
//  Created by 홍승완 on 2023/06/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int>arr;
vector<int>lis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        arr.push_back(tmp);
    }
    lis.push_back(arr[0]);
    int idx=0;
    for(int i=1;i<n;i++){
        if(lis[idx]<arr[i]){
            lis.push_back(arr[i]);
            idx++;
        }
        else{
            int targetIdx= lower_bound(lis.begin(), lis.end(), arr[i])-lis.begin();
            lis[targetIdx]=arr[i];
        }
    }
    
    cout<<idx+1<<"\n";
    
    return 0;
}
