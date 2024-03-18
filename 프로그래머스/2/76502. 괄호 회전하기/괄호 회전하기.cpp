#include <bits/stdc++.h>

using namespace std;
// 올바른 괄호 문자열?
string rotate(string str, int n) {
    string l=str.substr(0,n);
    string r=str.substr(n);
    return r+l;
}
int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++){
        string tar = rotate(s,i);
        stack<char>st;
        for(int i=0;i<tar.size();i++){
            if(st.empty()){
                st.push(tar[i]);
                continue;
            }
            if(st.top()=='['&&tar[i]==']'
               ||st.top()=='('&&tar[i]==')'
               ||st.top()=='{'&&tar[i]=='}'){
                st.pop();
            }
            else{
                st.push(tar[i]);
            }
        }
        if(st.empty()){
            answer++;
        }
    }
    
    return answer;
}