//
//  main.cpp
//  1920
//
//  Created by 홍승완 on 2022/05/14.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k;
int arr[100001];
// 이진탐색 직접구현
//void find(int k){
//    int st=0,ed=n-1;
//    int mid=(st+ed)/2;
//    while(st<=ed){
//        mid=(st+ed)/2;
//        if(arr[mid]<k){
//            st=mid+1;
//        }
//        else if(arr[mid]>k){
//            ed=mid-1;
//        }
//        else{
//            cout<<1<<"\n";
//            return ;
//        }
//    }
//    cout<<0<<"\n";
//}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>k;
        //find(k);
        if(binary_search(arr,arr+n,k))
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }
    return 0;
}
    
