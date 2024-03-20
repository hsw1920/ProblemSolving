#include <bits/stdc++.h>

using namespace std;
string dict[17]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
string transN(int n, int num) {
    string tmp="";
    while(num){
        int a=num%n;
        tmp+=dict[a];
        num/=n;       
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    // 0 1 1 0 1 1 1 0 0 1 0 1 1 1 0 1 1 1
    // t개 인원수 m, -> t*m이 최대 문자열 길이
    int curNum=0;
    string str = "0";
    while(1) {
        if(str.size()>t*m) break;
        str+=transN(n, curNum);
        curNum++;
    }
    
    for(int i=0;i<str.size();i++){
        if((i%m)+1==p)answer+=str[i];
        if(answer.size()==t)break;
    }

    return answer;
}