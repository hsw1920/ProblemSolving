//
//  main.cpp
//  10217
//
//  Created by 홍승완 on 2023/05/29.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pint;
int t,n,m,k,u,v,c,d;
int dp[101][10001];
vector<pair<int,pint>>edge[101];

void dstra(){
    dp[1][0]=0;
    priority_queue<pair<int,pint>,vector<pair<int,pint>>,greater<pair<int,pint>>>pq;
    pq.push({0,{0,1}});
    while(pq.size()){
        int curt=pq.top().first;
        int curd=pq.top().second.first;
        int cur=pq.top().second.second;
        
        pq.pop();
        if(dp[cur][curd]<curt)continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxtt=edge[cur][i].first;
            int nxtd=edge[cur][i].second.first;
            int nxt=edge[cur][i].second.second;
            if(curt+nxtt<dp[nxt][curd+nxtd] && curd+nxtd<=m){
                
                for(int j=curd+nxtd+1;j<=m;j++){
                    if(dp[nxt][j]<=curt+nxtt) break;
                    dp[nxt][j]=curt+nxtt;
                }
                dp[nxt][curd+nxtd]=curt+nxtt;
                pq.push({curt+nxtt,{curd+nxtd,nxt}});
            }
            
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    // 인천시작 LA도착
    // m 비용 이하로 가장 빠른길 ㄱㄱ

    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=1e9;
            }
        }
        for(int i=0;i<=n;i++)edge[i].clear();
    
        for(int i=1;i<=k;i++){
            cin>>u>>v>>c>>d;
            edge[u].push_back({d,{c,v}});
        }
        dstra();
        int res=1e9;
        for(int i=0;i<=m;i++){
            if(dp[n][i]<res)
                res=dp[n][i];
        }
        if(res==1e9){
            cout<<"Poor KCM\n";
        }else {
            cout<<res<<"\n";
        }
    }
    
    return 0;
}
