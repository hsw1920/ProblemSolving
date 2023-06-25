//
//  main.cpp
//  2150
//
//  Created by 홍승완 on 2023/06/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

vector<int>edge[10001];
vector<int>rev_edge[10001];
vector<vector<int>>res;
int visited[10001];
int V,E,A,B;
stack<int>st;

void dfs(int x){
    visited[x]=1;
    for(int i=0;i<edge[x].size();i++){
        if(visited[edge[x][i]]==0){
            dfs(edge[x][i]);
        }
    }
    st.push(x);
}

void dfs_scc(int x, vector<int>&v){
    visited[x]=1;
    v.push_back(x);
    for(int i=0;i<rev_edge[x].size();i++){
        int cur=rev_edge[x][i];
        if(visited[cur]==0){
            dfs_scc(cur, v);
        }
    }
}

int main() {
    cin>>V>>E;
    for(int i=0;i<E;i++){
        cin>>A>>B;
        edge[A].push_back(B);
        rev_edge[B].push_back(A);
    }
    for(int i=1;i<=V;i++){
        sort(edge[i].begin(),edge[i].end());
        sort(rev_edge[i].begin(),rev_edge[i].end());
        if(visited[i]==0){
            dfs(i);
        }
    }
    
    fill(visited,visited+V+1,0);
    vector<int>v;
    while(st.size()){
        int cur=st.top();
        st.pop();
        if(visited[cur]==0){
            dfs_scc(cur,v);
            sort(v.begin(),v.end());
            res.push_back(v);
            v.clear();
        }
    }
    
    cout<<res.size()<<"\n";
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<-1<<"\n";
    }
    
    return 0;
}
