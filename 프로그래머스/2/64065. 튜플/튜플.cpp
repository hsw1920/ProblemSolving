#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pint;
map<int,int>mp;
priority_queue<pint,vector<pint>> pq;

vector<int> solution(string s) {
    vector<int> answer;
    string num="";
    for(int i=0;i<s.size();i++) {
        if(s[i]>='0'&&s[i]<='9'){
            num+=s[i];
        }
        else {
            if(!num.empty()){
                mp[stoi(num)]++;
                num="";
            } else{
                num="";
            }
        }
    }
    
    for(auto k:mp){
        pq.push({k.second,k.first});
    }
    while(pq.size()){
        answer.push_back(pq.top().second);
        pq.pop();
    }
    
    return answer;
}