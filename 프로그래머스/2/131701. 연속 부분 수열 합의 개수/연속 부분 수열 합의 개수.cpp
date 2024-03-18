#include <bits/stdc++.h>


using namespace std;
// 연속하는 부분수열의 합은 몇가지?
// 7 9 1 1 4 7 9 1 1 
set<int>s;

void getSet(vector<int> v, int n){
    int psum[2001]={0,};
    for(int i=1;i<=v.size();i++){
        psum[i]=psum[i-1]+v[i-1];
    }
    for(int i=n;i<=v.size();i++){
        s.insert(psum[i]-psum[i-n]);
    }
}

int solution(vector<int> elements) {
    int answer = 0;
    vector<int>v=elements;
    for(auto k: elements)
        v.push_back(k);
    v.pop_back();
    for(int i=1;i<=elements.size();i++){
        getSet(v,i);
    }
    
    answer=s.size();
    return answer;
}