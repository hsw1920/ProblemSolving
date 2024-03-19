#include <bits/stdc++.h>

using namespace std;
// n: 1000만
// left ~ right : 10만
// 1행 -> 1
// 2행 -> 2...
// a, b: 몫, 나머지
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i=left;i<=right;i++) {
        if(i/n >= i%n)answer.push_back(i/n+1);
        else answer.push_back(i%n+1);
    }

    return answer;
}