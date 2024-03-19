#include <bits/stdc++.h>

using namespace std;
// n을 k진수로 바꿨을 때
// 조건에 맞는 소수의 개수
// 양쪽에 0
// 오른쪽/왼쪽에 0
// 아무것도 X

bool isPrime(long long num){
    if(num<=1)return false;
    for(long long i=2;i<=sqrt(num);i++){
        if(num%i==0) return false;
    }
    return true;
}

vector<int> transK(int k, int num){
    vector<int>tmp;
    while(num){
        int cur = num%k;
        tmp.push_back(cur);
        num/=k;
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int>v = transK(k, n);
    long long num=0;
    for(int i=0;i<v.size();i++){
        if(v[i]!=0){
            num*=10;
            num+=v[i];
        }else{
            if(isPrime(num))answer++;
            num=0;
        }
    }
    if(isPrime(num))answer++;
    
    return answer;
}