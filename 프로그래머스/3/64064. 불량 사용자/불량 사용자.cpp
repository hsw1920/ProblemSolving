#include <bits/stdc++.h>

using namespace std;

set<string>res;
vector<vector<string>>plist;

void dfs(string str, int cnt, set<string>st){
    // set에 저장하기
    if(cnt==plist.size()){
        if(st.size()==cnt){
            string tmp="";
            for(auto k:st){
                tmp+=k;
            }
            res.insert(tmp);
        }
        return ;
    }
    
    for(int i=0;i<plist[cnt].size();i++){
        set<string>tmpst = st;
        string cur=plist[cnt][i];
        tmpst.insert(cur);
        dfs(cur,cnt+1,tmpst);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    for(int i=0;i<banned_id.size();i++){
        // ban일수 있는 유저리스트
        vector<string>ban;
        string cban=banned_id[i];
        for(int j=0;j<user_id.size();j++){
            string cusr=user_id[j];
            if(cban.size()!=cusr.size())continue;
            bool valid=true;
            for(int k=0;k<cban.size();k++){
                if(cban[k]=='*')continue;
                else if(cban[k]==cusr[k])continue;
                else {
                    valid=false;
                    break;
                }
            }
            // 가능하면 ban에 넣음.
            if(valid){
                ban.push_back(cusr);   
            }
        }
        plist.push_back(ban);
    }
    
    for(int i=0;i<plist[0].size();i++){
        set<string>st;
        string cur=plist[0][i];
        st.insert(cur);
        dfs(cur,1,st);
    }
    
    answer = res.size();
    
    return answer;
}