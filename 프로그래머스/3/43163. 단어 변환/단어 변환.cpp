#include <bits/stdc++.h>

using namespace std;

vector<string> dict;
unordered_map<string,int> dist;
unordered_map<string,vector<string>>mp;
typedef pair<int, string> pis;
bool isValid(string a, string b){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])cnt++;
    }
    return cnt==1;
}

void dstra(string begin, string target){
    priority_queue<pis,vector<pis>,greater<pis>>pq;
    dist[begin]=0;
    pq.push({dist[begin], begin});
    
    while(pq.size()){
        string cur=pq.top().second;
        int curd=pq.top().first;
        vector<string> curDict = mp[cur];
        pq.pop();

        for(auto k: curDict){
            string nxt = k;
            int nxtd = 1;
            
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                pq.push({dist[nxt],nxt});
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    sort(words.begin(),words.end());
    words.erase(unique(words.begin(),words.end()),words.end());
    
    for(int i=0;i<words.size();i++){
        string cur = words[i];
        dict.clear();
        for(int j=0;j<words.size();j++){
            string nxt = words[j];
            if(cur!=nxt && isValid(cur,nxt)){
                dict.push_back(nxt);
            }
        }
        mp[cur]=dict;
    }
    // dist 초기화
    for(auto k: words){
        dist[k]=1e9;
    }
    
    dstra(begin, target);
    
    answer=dist[target];
    
    return answer;
}