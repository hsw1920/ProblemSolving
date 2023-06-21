//
//  main.cpp
//  13141
//
//  Created by 홍승완 on 2023/06/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define init cin.tie(0)->ios_base::sync_with_stdio(0)

using namespace std;

int n,m,s,e,l;
int dp[201][201];
int res[201];
int S[20001];
int E[20001];
int L[20001];

int main() {
    init;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=1e9;
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=m;i++){
        cin>>s>>e>>l;
        S[i]=s;
        E[i]=e;
        L[i]=l;
        dp[s][e]=min(dp[s][e],l);
        dp[e][s]=min(dp[e][s],l);
        
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
    
    int mn = 1e9;
    // 가장 오래걸리는 간선찾기
    // n개 시작점에 대해서 m개의 간선을 모두 확인하면 됨
    for(int i=1;i<=n;i++){
        int mx = 0;
        for(int j=1;j<=m;j++){
            // 시작점에서 해당간선의 시작점 + 시작점에서 해당간선의 끝점 + 해당간선의 가중치
            mx=max(mx,dp[i][S[j]]+dp[i][E[j]]+L[j]);
        }
        mn=min(mn,mx);
    }
    
    // a,b를 연결하는 가중치가 c인 간선이 모두 타는 시간
    // ((s->a)+(s->b)+c)/2로 계산가능
    cout<<mn/2<<"."<<mn%2*5;
    
    return 0;
}
