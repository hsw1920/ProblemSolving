#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int>mset;
    for(int i=0;i<operations.size();i++){
        string oper = operations[i].substr(0,1);
        // 삽입
        if(oper == "I"){
            int num = stoi(operations[i].substr(2));
            mset.insert(num);
        }
        // 삭제
        else {
            string first = operations[i].substr(2,1);
            // 최솟값
            if(first == "-"){
                if(mset.size()){
                    mset.erase(*mset.begin());
                }
            }
            // 최댓값
            else {
                if(mset.size()){
                    mset.erase(*(--mset.end()));
                }
            }
        }    
    }
    
    if(mset.size()){
        return {*(--mset.end()),*mset.begin()};
    }
    
    return {0,0};
}