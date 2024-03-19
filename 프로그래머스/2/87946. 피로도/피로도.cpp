#include <bits/stdc++.h>

using namespace std;

// 최소필요피로도, 소모피로도
// 현재피로도 k
// 유저 탐험가능 최대 던전수
// dp-> 현재피로도, 던전갯수 ㄴㄴ
typedef pair<int,int> pint;
int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    sort(dungeons.begin(),dungeons.end());
    
    do {
        int curK=k;
        int ans=0;
        for(auto cur: dungeons){
            if(curK>=cur[0]){
                curK-=cur[1];
                ans++;
            }
        }    
        answer=max(ans,answer);
    } while(next_permutation(dungeons.begin(),dungeons.end()));
    
    return answer;
}