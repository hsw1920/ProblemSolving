#include <bits/stdc++.h>

using namespace std;

// 문자열에서 0을 모두 제거
// 2진법으로 바꿈

// 1111 -> 길이 4 -> 2진법으로 표현 100
int res;
string solve(string s) {
    cout<<"target: "<<s<<"\n";
    int prev = s.size();
    int tmp=0;
    string trans = "";
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            res++;
        }
        else {
            trans+="1";
        }
    }  
    int afterLength = trans.size();
    string result = "";
    while(afterLength){
        if(afterLength%2==0){
            result+="0";
        } else {
            result+="1";
        }
        afterLength/=2;
    }
    
    reverse(result.begin(),result.end());
    cout<<"result: "<<result<<"\n";
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    string target = s;
    res=0;
    int k=0;
    while(target!="1"){
        k++;
        target=solve(target);
        cout<<target<<"\n\n";
    }
    
    answer.push_back(k);
    answer.push_back(res);
    
    return answer;
}