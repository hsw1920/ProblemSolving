#include <iostream>
using namespace std;

// K칸 앞으로 점프 -> K만큼 건전지 사용
// 현재 온 거리 X 2 -> 순간이동(건전지 X)
// N만큼 떨어진 장소로 이동해야함.
// 점프를 최솟값

// dp ㄴㄴ 
// 2의 제곱 ->비트마스킹 1의 개수

int solution(int n) {
    int ans = 0;
    while(n) {
        if(n%2==1){
            ans++;
        }
        n/=2;
    }

    return ans;
}