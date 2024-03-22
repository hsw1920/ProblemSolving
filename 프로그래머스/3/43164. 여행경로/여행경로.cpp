#include <bits/stdc++.h>

using namespace std;
unordered_set<string>uset;
unordered_map<int,string>umapIS;
unordered_map<string,int>umapSI;
vector<int>edge[10001];
vector<vector<string>>res;
int tCnt;

void dfs(int cur, deque<int>q){
    
    if(q.size()==tCnt){
        vector<string>v;
        while(q.size()){
            int id = q.front();
            string s = umapIS[id];
            v.push_back(s);
            q.pop_front();
        }
        res.push_back(v);
        return;
    }
    
    for(int i=0;i<edge[cur].size();i++){
        int nxtId = edge[cur][i];
        int tmp=nxtId;
        if(nxtId != -1){
            q.push_back(nxtId);
            edge[cur][i]=-1;
            dfs(nxtId, q);
            q.pop_back();
            edge[cur][i]=tmp;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    tCnt = tickets.size()+1;
    for(auto k: tickets){
        uset.insert(k[0]);
        uset.insert(k[1]);
    }
    int idx=0;
    int st=-1;
    for(auto k:uset){
        umapIS[idx]=k;
        umapSI[k]=idx;
        if(k=="ICN")st=idx;
        idx++;
    }
    for(auto k: tickets){
        int u = umapSI[k[0]];
        int v = umapSI[k[1]];
        edge[u].push_back(v);
    }
    deque<int>q;
    q.push_front(st);
    dfs(st,q);
    sort(res.begin(),res.end());
    
    answer = res[0];

    return answer;
}