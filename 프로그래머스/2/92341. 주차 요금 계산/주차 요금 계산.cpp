#include <bits/stdc++.h>

using namespace std;
typedef struct user{
    string id;
    bool state;
    int lastTime;
    int sumTime;
}User;
vector<User> users;
bool findId(string id){
    for(auto k: users){
        if(k.id==id){
            return true;
        }
    }
    return false;
}

void updateOut(string id, int nxtTime){
    for(int i=0;i<users.size();i++){
        User k = users[i];
        if(id == k.id){
            users[i].sumTime += (nxtTime-k.lastTime);
            users[i].state = false;
        }
    }
}
void updateIn(string id, int nxtTime){
    for(int i=0;i<users.size();i++){
        User k = users[i];
        if(id == k.id){
            users[i].lastTime = nxtTime;
            users[i].state = true;
        }
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    
    for(int i=0;i<records.size();i++){
        string rec=records[i];
        int h = stoi(rec.substr(0,2));
        int m = stoi(rec.substr(3,2));
        int time = h*60+m;
        string id = rec.substr(6,4);
        bool state = false;
        if(rec[11]=='I'){
            state = true;
        }else {
            // 출차하면 false됨.
            state = false;
        }
        
        if(!findId(id)){
            User curUser = {id, state, time, 0};
            users.push_back(curUser);
            continue;
        }
        else {
            // 출차할 때
            // sumTime, lastTime 업데이트
            if(!state){
                updateOut(id,time);
            }
            // 입차할 떄
            else {
                updateIn(id,time);
            }
        }
    }
    vector<pair<string,int>>res;
    int T=fees[0];
    int F=fees[1];
    int dT=fees[2];
    int dF=fees[3];
    for(int i=0;i<users.size();i++){
        // 입차중인 차
        if(users[i].state){
            users[i].sumTime += (60*23+59 - users[i].lastTime);
            
            int pay = F;
            int time = max(0, users[i].sumTime-T);
            int tmp = ((time+dT-1)/dT);
            tmp *= dF;
            pay += tmp;
            
            res.push_back({users[i].id, pay});
        }
        // 출차중인 차
        else {
            int pay = F;
            int time = max(0, users[i].sumTime-T);
            int tmp = ((time+dT-1)/dT);
            
            tmp *= dF;
            pay += tmp;
            
            res.push_back({users[i].id, pay});
        }
    }
    
    sort(res.begin(),res.end());
    for(auto k:res){
        answer.push_back(k.second);
    }
    
    return answer;
}