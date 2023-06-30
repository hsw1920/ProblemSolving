//
//  main.cpp
//  1449
//
//  Created by 홍승완 on 2023/06/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,l;
int arr[1001];
int main() {
    
    cin>>n>>l;
    // 1-> 12345
    // 길이가 L인 테이프 무한개
    // 좌우 0.5간격으로 물을 막음
    // 길이L이 주어졌을 때 필요한 테이프 최소개수
    // 테이프 못자름, 겹쳐붙이기 가능
    // 물이 새는곳의 위치가 주어짐
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int st=arr[0];
    
    int res=0;
    
    for(int i=1;i<n;i++){
        if(l<=arr[i]-st){
            res++;
            st=arr[i];
        }
    }
    cout<<res+1<<"\n";
    return 0;
}
