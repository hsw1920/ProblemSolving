#include <bits/stdc++.h>

using namespace std;

// 자연수 n개의 원소의 합이 s
// 자연수 n개의 원소의 곱이 최대가 되는 집합
// n<=10000
vector<int> solution(int n, int s) {
    if(n>s) return {-1};
    vector<int>v;
    int res = s%n;
    int k = s/n;
    while(n--){
        if(s>=k){
            v.push_back(k);
            s-=k;
        }
    }
    for(int i=0;i<res;i++){
        v[i]++;
    }
    sort(v.begin(),v.end());
    return v;
}