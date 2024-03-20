#include <bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>>pq;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(auto k:works) pq.push(k);
    
    while(n--){
        int cur = max(0,pq.top()-1);
        pq.pop();
        pq.push(cur);
    }
    
    while(pq.size()){
        answer += pow(pq.top(),2);
        pq.pop();
    }
    
    return answer;
}