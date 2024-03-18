#include <bits/stdc++.h>

using namespace std;

// 귤 k개 고르기
// 서로다른종류의 수 최소화
// 6개 판매, -> 서로 다른 종류 최소화
// 배열 10만 -> sort nlogn 가능
// pair에 넣고 정렬?
// pq에 넣기? -> 이거다
typedef pair<int,int> pint;
priority_queue<pint, vector<pint>>pq;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    sort(tangerine.begin(),tangerine.end());
    int prev=tangerine[0];
    int cnt=1;
    for(int i=1;i<tangerine.size();i++){
        int cur= tangerine[i];

        if(i==tangerine.size()-1){
            if(prev!=cur) {
                pq.push({cnt,prev});
                pq.push({1,cur});
            } else {
                cnt++;
                pq.push({cnt,cur}); // 끝
            }
        } else {
            if(prev!=cur) {
                pq.push({cnt,prev});
                cnt=1;
            } else {
                cnt++;
            }
        }
        
        prev=cur;
    }
    
    if(tangerine.size()==1){
        return 1;
    }
    
    while(k>0&&pq.size()){
        int cnt = pq.top().first;
        k-=cnt;
        answer++;
        pq.pop();
    }
    
    return answer;
}