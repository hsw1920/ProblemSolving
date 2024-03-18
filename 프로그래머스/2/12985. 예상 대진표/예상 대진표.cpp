#include <bits/stdc++.h>

using namespace std;

int next(int cur) {
    return (cur - 1) / 2 + 1;
}

bool isValid(int a, int b){
    if(a&1 && a+1==b) return true;
    return false;
}

int solution(int n, int a, int b)
{
    int answer = 1;
    if(a<b){
        while(a) {
            if(isValid(a,b)) {
                return answer;
            }
            answer++;
            a=next(a);
            b=next(b);
        }
    } else {
        while(b) {
            if(isValid(b,a)) {
                return answer;
            }
            answer++;
            a=next(a);
            b=next(b);
        }
    }

    return answer;
}