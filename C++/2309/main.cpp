//
//  main.cpp
//  2309
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 일곱난쟁이 키합 100
     int arr[9];
     for(int i=0;i<9;i++){
       cin>>arr[i];
     }
     sort(arr,arr+9);
    // 정렬하고 7개합 100되는 난쟁이들을 출력
    // n이 9밖에 안돼서 순열로 해결가능함.
     do{
       int sum=0;
       for(int i=0;i<7;i++){
         sum+=arr[i];
       }
       if(sum==100){
         for(int i=0;i<7;i++){
           cout<<arr[i]<<"\n";
         }
         break;
       }
     }while(next_permutation(arr,arr+9));
    return 0;
}
