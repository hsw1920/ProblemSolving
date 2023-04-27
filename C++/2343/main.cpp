//
//  main.cpp
//  2343
//
//  Created by 홍승완 on 2023/04/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n,m,arr[100001];
int l=1,r;
vector<int>v;

// n개의 강의
// m개의 블루레이에 모든 기타동영상 녹화
// 블루레이의 크기를 최소로 하고 m은 모두 같은 크기여야함
// 각 강의의 길이가 n개 주어짐
// 최소의 블루레이 크기는?

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    // N은 레슨의 수, M은 블루레이의 갯수
    cin >> n >> m;
    
    long long sum = 0, low = -1;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        low = max(low, arr[i]);
    }
    
    long long high = sum;
    
    while (low <= high) {
        long long cnt = 0, tempSum = 0;
        long long mid = (low + high) / 2;
        
        for (int i = 0; i < n; i++) {
            if (tempSum + arr[i] > mid) {
                tempSum = 0;
                cnt += 1; // 블루레이 갯수 1 증가
            }
            tempSum += arr[i];
        }
        if (tempSum != 0) cnt += 1;
        // 블루레이 크기로 가정한 mid보다 작아서 1 증가시키지 못했을 경우
        
        // 갯수가 M 이하일 때는, high 값을 줄여본다.
        if (cnt <= m) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    cout << low;
    return 0;
}
