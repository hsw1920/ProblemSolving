//
//  main.cpp
//  18870
//
//  Created by 홍승완 on 2022/05/14.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int tmp[1000001];
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp[i];
        arr.push_back(tmp[i]);
    }
    sort(arr.begin(),arr.end());
    
    //벡터 unique()를 이용한 중복제거 루틴
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    
    //이분 탐색을 통해 각 원소가 중복제거된 벡터 arr의 어느 인덱스에 있는지 출력
    for(int i=0;i<n;i++){
        cout<<lower_bound(arr.begin(),arr.end(),tmp[i])-arr.begin()<<" ";
    }
    return 0;
}
