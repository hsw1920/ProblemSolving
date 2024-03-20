#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int>instack,outstack;
    for(auto k: numbers) outstack.push(k);
    int initial = outstack.top();
    answer.push_back(-1);
    
    instack.push(initial);
    outstack.pop();
    
    while(outstack.size()){
        int cur = outstack.top();
        outstack.pop();
        // instack의 top에 자기보다 큰게 있다면
        int inTop=instack.top();
        if(cur<inTop){
            instack.push(cur);
            answer.push_back(inTop);
        }
        // instack의 top에 자기보다 큰게 없다면
        else {
            // while로 나올때 까지 pop하면서 찾기.
            while(instack.size()){
                inTop = instack.top();
                if(cur<inTop){
                    answer.push_back(inTop);
                    break;
                }
                instack.pop();
            }
            if(instack.size()==0){
                answer.push_back(-1);
            }
            instack.push(cur);
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}