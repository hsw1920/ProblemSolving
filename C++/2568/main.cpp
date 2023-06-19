//
//  main.cpp
//  2568
//
//  Created by 홍승완 on 2023/06/18.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// DP
// N<=10만
// LIS -> N log(N)
// 이분탐색 LIS

int n;
vector<pair<int,int>>arr;
vector<int>lis;
vector<int>idxArr;
vector<int>ans;
int binarySearch(int s, int e, int val){
    
    while(s<e){
        int mid=(s+e)/2;
        if(lis[mid]<val){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return e;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    arr.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;

    }
    sort(arr.begin(),arr.end());
    
    lis.push_back(arr[0].second);

    int i=1;
    int j=0;
    idxArr.push_back(0);

    while(i<n){
        if(lis[j]<arr[i].second){
            lis.push_back(arr[i].second);
            j++;
            idxArr.push_back(j);
        }
        // 이분탐색으로 arr[i].second가 들어갈 자리를 찾음
        else{
//            int idx=binarySearch(0, j, arr[i].second);
//            lis[idx]=arr[i].second;
//            idxArr.push_back(idx);
            vector<int>::iterator iter = lower_bound(lis.begin(), lis.end(), arr[i].second);
            *iter = arr[i].second;
            idxArr.push_back(iter - lis.begin());
        }

        i++;
    }
    // 없애야하는 전깃줄 최소 (LIS(크기만))
    cout<<n-(j+1)<<"\n";
    
    // LIS 크기가 아닌 LIS 최장증가부분수열 자체를 구하기?
    // -> 역추적방식, Dijkstra에서도 이런 방식을 사용함
    
    int cur = lis.size() - 1;
    for (int i = idxArr.size() - 1; i >= 0; i--) {
        if (cur == idxArr[i]) cur--;
        else ans.push_back(arr[i].first);
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<"\n";
    
    
    return 0;
}
