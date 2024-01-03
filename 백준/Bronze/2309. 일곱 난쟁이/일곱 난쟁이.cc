#include <iostream>
#include <cstring>
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