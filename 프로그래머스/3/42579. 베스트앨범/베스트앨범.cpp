#include <bits/stdc++.h>

using namespace std;

// 가장 많이 재생된 장르 먼저
// 장르내 가장 많이 재생
// 장르내 재생횟수 같은 것 중 id가 낮은 노래 먼저

// 장르내에서 가장 많이 재생된 노래 두 개씩모으기

typedef pair<int,string> pis;
typedef pair<int,int> pint;
unordered_map<string,int>genreAll;
priority_queue<pis,vector<pis>>pq;

priority_queue<pint,vector<pint>>songpq;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n= genres.size(); //100미만
    for(int i=0;i<n;i++){
        string cur = genres[i];
        int songPlay = plays[i];
        
        genreAll[cur]+=songPlay;
    }
    
    // 많이 재생된 장르 순
    for(auto cur: genreAll){
        pq.push({cur.second, cur.first});
    }
    
    while(pq.size()){
        vector<pair<int,int>>ans;
        string genre = pq.top().second;
        // 해당 장르의 모든 노래 구하기
        for(int i=0;i<plays.size();i++){
            if(genres[i]==genre)
                ans.push_back({plays[i], i});
        }
        sort(ans.begin(),ans.end(),compare);
        answer.push_back(ans[0].second);
        if(ans.size()>1)
            answer.push_back(ans[1].second);
        
        pq.pop();
    }
    
    return answer;
}