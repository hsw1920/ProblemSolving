#include <bits/stdc++.h>

using namespace std;

// 무작위 자연수 받음
// 각 사원은 한번씩 경기
// A팀, B팀에서 각 한명씩 나와 수를 공개함
// 숫자 큰쪽이 이기고 팀이 승점1점 얻음
// 숫자 같으면 승점 없음
// Output
// B팀이 얻을 수 있는 최대승점
// A, B 길이 10만 -> DP네

int visited[100001]={0,};

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(B.begin(),B.end());
    for(int i=0;i<A.size();i++){
        int cur = A[i];
        int idx = upper_bound(B.begin(),B.end(),cur)-B.begin();
        if(visited[idx]==0 && idx<B.size()){
            visited[idx]=1;    
            answer++;
        }
        else{
            int chk=0;
            for(int j=idx;j<B.size();j++){
                if(visited[j]==0){
                    visited[j]=1;   
                    answer++;
                    chk=1;
                    break;
                }
            }
            if(chk==0){
                for(int j=0;j<=idx;j++){
                    if(visited[j]==0){
                        visited[j]=1;
                        chk=1;
                        break;
                    }
                }
            }
        }
    }
    
    return answer;
}