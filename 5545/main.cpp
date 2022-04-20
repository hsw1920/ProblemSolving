//
//  main.cpp
//  5545
//
//  Created by 홍승완 on 2022/04/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,c; //토핑개수, 도우가격, 토핑가격, 도우열량
    cin >> n>>a>>b>>c;
 
    vector<int> d; //토핑 열량 벡터
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        d.push_back(t);
    }
    sort(d.begin(), d.end(), greater<int>()); //내림차순 정렬
 
    int dcal = c/a; //1원 당 도우 열량
    
    int best = dcal; //최고의 피자의 1원 당 열량 (토핑선택안함)
 
    int sumPrice = a; //총 가격
    int sumCal = c; //총 열량
    for (int i = 0; i < n; i++) {
        sumPrice += b;
        sumCal += d[i];
        if (best < sumCal / sumPrice) {
            best = sumCal / sumPrice;
        }
    }
 
    cout << best;
    return 0;
}
