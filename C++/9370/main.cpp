//
//  main.cpp
//  9370
//
//  Created by 홍승완 on 2023/06/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T;
int n,m,t;
int s,g,h;
int a,b,d;
int x;
typedef pair<int,int> pint;
vector<pint>edge[2001];
vector<int>target;
vector<int>ans;
vector<int>distS,distGH;
int gh;

vector<int> dijkstra(int s, vector<int>dist){
    dist.resize(n+1);
    fill(dist.begin(),dist.end(),1e9);
    dist[s]=0;
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    pq.push({dist[s],s});
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        pq.pop();
        if(curd>dist[cur])continue;
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i].second;
            int nxtd=edge[cur][i].first;
            
            if(dist[nxt]>curd+nxtd){
                dist[nxt]=curd+nxtd;
                pq.push({dist[nxt],nxt});
            }
            
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>T;
    while(T--){
        
        cin>>n>>m>>t; // 교차로, 도로, 목적지 6 9 2
        cin>>s>>g>>h; // 출발지, g~h 정점 사이를 지남 2 3 1
        
        // init
        ans.clear();
        target.clear();
        distS.clear();
        distGH.clear();
        for(int i=0;i<=n;i++){
            edge[i].clear();
        }
        
        // 간선
        for(int i=0;i<m;i++){
            cin>>a>>b>>d; // a,b사이에 길이d 양방향간선
            edge[a].push_back({d,b});
            edge[b].push_back({d,a});
            if((a==g&&b==h)||(a==h&&b==g))
                gh=d;
        }
        // t개의 목적지 후보, 모두 다른 위치, 출발지와 모두 다름
        for(int i=0;i<t;i++){
            cin>>x;
            target.push_back(x);
        }
        
        // (s->g) + (g-h) + (h-> 목적지) ==  (s->목적지)
        // 와 같다면 가능한 후보임
        
        // 출발지에서 다익스트라 돌리기
        distS=dijkstra(s,distS);
        
        if(distS[g]>distS[h])swap(g,h);
        
        // h에서 다익스트라 돌리기
        distGH=dijkstra(h,distGH);
        
        // 목적지가 들어오면? -> valid체크하고 ans에 넣기
        for(int i=0;i<t;i++){
            int curTarget = target[i];
            if(distS[curTarget]==distS[g]+gh+distGH[curTarget]){
                ans.push_back(curTarget);
            }
        }
        
        // output
        // 가능한 후보들을 오름차순의 정수로 출력함
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        
    }
    
    
    return 0;
}
