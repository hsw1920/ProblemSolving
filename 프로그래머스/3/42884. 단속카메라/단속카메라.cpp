#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end());
    int st=routes[0][0],ed=routes[0][1];
    for(int i=0;i<routes.size();i++){
        int curst=routes[i][0];
        int cured=routes[i][1];
        if(curst<=ed){
            st=curst;
            ed=min(ed,cured);
            continue;
        }
        answer++;
        st=curst;
        ed=cured;
    }
    // 마지막 카메라 포함
    answer++;
    
    return answer;
}