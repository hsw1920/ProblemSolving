//
//  main.cpp
//  3474
//
//  Created by 홍승완 on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T,N;

int main() {
    // 2와 5가 더 적게 들어간 수를 출력
    // N,N-1,...,2,1을 소인수분해하여 2와 5의 개수를 모두 각각 구하여 그중 min값이 0의 개수이다.
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        int five=0;
        int two=0;
        for(int j=2;j<=N;j*=2){
            two += N/j;
        }
        for(int j=5;j<=N;j*=5){
            five += N/j;
        }
        cout<<min(two,five)<<"\n";
    }
    return 0;
}
