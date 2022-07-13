//
//  main.cpp
//  1325
//
//  Created by 홍승완 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int a,b; // a가 b를 신뢰 => b해킹시 a도 해킹 가능
int res=0,tmp,idx;
vector<int> v[10001];
vector<int> resIdx;
int visited[10001];
void dfs(int x){
    tmp++;
    visited[x]=1;
    if(v[x].size()==0){
        return;
    }
    for(int i=0;i<v[x].size();i++){
        if(!visited[v[x][i]]) dfs(v[x][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[b].push_back(a);
    }
    for(int i=1;i<=10000;i++){
        tmp=0;
        for(int j=0;j<=10000;j++)visited[j]=0;
        dfs(i);
        if(res<tmp){
            res=tmp;
            resIdx.clear();
            resIdx.push_back(i);
        }
        else if(res==tmp){
            resIdx.push_back(i);
        }
    }
    sort(resIdx.begin(),resIdx.end());
    for(auto i: resIdx){
        cout<<i<<" ";
    }
    return 0;
}
