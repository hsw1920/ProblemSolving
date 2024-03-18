#include <bits/stdc++.h>

using namespace std;

//10일동안 회원자격, 할인행사, 하루에 하나 구매
// 10일연속 원하는 제품과 수량이 일치하면 날짜에 맞춰 회원가입하기
// 수량일치하는 날짜가 여러개면? -> 그냥 개수만 리턴
// 원하는 품목,수량 주어짐 <= 10
// 할인품목 <= 10만
// 10만 * 10개 -> 100만 완탐 가능

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int>mp;
    for(int i=0;i<want.size();i++){
        mp[want[i]]=number[i];
    }
    
    for(int i=0;i<discount.size();i++){
        map<string,int>tmap=mp;
        vector<string>twant=want;
        vector<int>tnum=number;
        
        int mn= min(i+10, int(discount.size()));

        for(int j=i;j<mn;j++) {
            string cur = discount[j];
            if(tmap[cur]>0)
                tmap[cur]--; 
        }
        int sum=0;
        for(auto k:tmap){
            sum+=k.second;
        }
        if(sum==0){
            answer++;
        }
        
    }
    return answer;
}