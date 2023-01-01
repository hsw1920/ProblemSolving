//
//  main.cpp
//  21940
//
//  Created by 홍승완 on 2023/01/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int maps[201][201];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    
    int n,m,a,b,t,K,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            maps[i][j]=1e9;
            if(i==j)maps[i][j]=0;
        }
    }
    
    for(int i=1;i<=m;i++){
        cin>>a>>b>>t;
        maps[a][b]=min(maps[a][b],t);
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                maps[i][j]=min(maps[i][j],maps[i][k]+maps[k][j]);
            }
        }
    }
    cin>>K;
    int tmp;
    vector<int>v;
    while(K--){
        cin>>tmp;
        v.push_back(tmp);
    }
    
    
    int ans=2e9;
    set<int>answer;
    
    for(int i=1;i<=n;i++){
        int res=0;
        
        for(int j=0;j<v.size();j++){
            int cur = v[j];
            res=max(res,maps[cur][i]+maps[i][cur]);
        }
        if(ans>res){
            answer.clear();
            answer.insert(i);
            ans=res;
        }
        else if (ans == res){
            answer.insert(i);
        }
    }

    for(auto u:answer){
        cout<<u<<" ";
    }
    
    // 왕복시간의 최대가 최소가 되는 값을 구하고 해당값들을 오름차순출력 -> set처리
    return 0;
}
