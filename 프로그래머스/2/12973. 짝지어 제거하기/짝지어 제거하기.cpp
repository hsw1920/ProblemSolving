#include <bits/stdc++.h>

using namespace std;

// baabaa
// 같은 알파벳 붙어있는거 찾고 제거
// 반복
// 문자열을 모두 제거할 수 있는지 확인하기

// 100만 -> N*log(N) ㅇㅋ

int solution(string s)
{
    stack<char>st;
    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(st.empty()) {
            st.push(s[i]);
            continue;
        }
        if(st.top()==s[i]) {
            st.pop();
        }
        else st.push(s[i]);
    }

    if(st.empty()) return 1;
    
    return 0;
}