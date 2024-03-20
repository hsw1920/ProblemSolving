#include <bits/stdc++.h>

using namespace std;

bool visited[201]={0,};

void dfs(int cur, vector<vector<int>>maps){
    for(int i=0;i<maps.size();i++){
        if(cur!=i && !visited[i] && maps[cur][i]){
            visited[i]=1;
            dfs(i,maps);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            answer++;
            dfs(i,computers);
        }
    }
    
    return answer;
}