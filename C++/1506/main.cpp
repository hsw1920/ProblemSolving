//
//  main.cpp
//  1506
//
//  Created by 홍승완 on 2023/06/24.
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

int N;
int visited[101];
int pay[101];
vector<vector<int>>edge;
vector<vector<int>>rev_edge;
int minNum=1e9;
int num=0;
stack<int>st;
int res=0;

void dfs(int x){
    visited[x]=1;
    for(int i=0;i<edge[x].size();i++){
        if(visited[edge[x][i]]==0){
            dfs(edge[x][i]);
        }
    }
    st.push(x);
}

void dfs2(int x){
    visited[x]=1;
    for(int i=0;i<rev_edge[x].size();i++){
        if(visited[rev_edge[x][i]]==0){
            dfs2(rev_edge[x][i]);
        }
    }
    if(minNum>pay[x]){
        minNum=pay[x];
        num=x;
    }
}

int main() {
    init
    cin>>N;
    edge.resize(N+1);
    rev_edge.resize(N+1);
    for(int i=1;i<=N;i++){
        cin>>pay[i];
    }
    for(int i=1;i<=N;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<N;j++){
            if(tmp[j]=='1'){
                edge[i].push_back(j+1);
                rev_edge[j+1].push_back(i);
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(visited[i]==0)
            dfs(i);
    }
    fill(visited,visited+N+1,0);
    
    while(st.size()){
        minNum=1e9;
        num=0;
        int cur=st.top();
        st.pop();
        if(visited[cur]==0){
            dfs2(cur);
            res+=minNum;
        }
    }
    
    cout<<res<<"\n";

    return 0;
}
