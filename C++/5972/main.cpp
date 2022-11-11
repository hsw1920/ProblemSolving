//
//  main.cpp
//  5972
//
//  Created by 홍승완 on 2022/11/11.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pint;
priority_queue<pint,vector<pint>,greater<pint>> pq;
vector<vector<pint>>v(50001);
int n,m;
int d[50001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int a,b,dis;
    for(int i=0;i<=n;i++){
        d[i]=1e9;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>dis;
        v[a].push_back({b,dis});
        v[b].push_back({a,dis});
    }
    pq.push({1,0});
    d[1]=0;
    int cur,nxt,nxtd,curd;
    while(pq.size()){
        cur = pq.top().first;
        curd = pq.top().second;
        pq.pop();
        for(int i=0;i<v[cur].size();i++){
            nxt = v[cur][i].first;
            nxtd = v[cur][i].second;
            if(d[nxt]>d[cur]+nxtd){
                d[nxt]=d[cur]+nxtd;
                pq.push({nxt,nxtd});
            }
        }
    }
    cout<<d[n]<<"\n";
    
    return 0;
}

