//
//  main.cpp
//  2295
//
//  Created by 홍승완 on 2022/05/14.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,k;
int tmp[1001]; // N=1000이기 때문에 O(N^2)정도로 접근해야한다.
vector<int>arr;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp[i];
    }
    sort(tmp,tmp+n);
    //a[i]+a[j]+a[k]=a[l] 을 만족시켜야함!
    // a[i]+a[j] 를 만드는 시간복잡도 O(N^2)
    // a[l]-a[k] 가 위 배열에 존재하는지 이분탐색하는 시간복잡도 O(lg(N^2))
    // => O(N^2 * log(N))이 된다.
    
    // 두 수의 합 O(N^2)
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            arr.push_back(tmp[i]+tmp[j]);
        }
    }
    sort(arr.begin(),arr.end());
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            int target=tmp[i]-tmp[j];
            //target이 arr안에 있어야함.
            if(binary_search(arr.begin(),arr.end(),target)){
                cout<<tmp[i];
                return 0;
            }
        }
    }
    return 0;
}
