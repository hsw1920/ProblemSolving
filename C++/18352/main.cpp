//
//  main.cpp
//  18352
//
//  Created by 홍승완 on 2023/05/03.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int n,m,k,x,a,b;
int dist[300001];
queue<int>q;
vector<int>edge[300001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>k>>x; // 거리정보, 출발도시
    for(int i=0;i<m;i++){
        cin>>a>>b;
        edge[a].push_back(b);
    }
    
    for(int i=0;i<=n;i++)dist[i]=987654321;
    dist[x]=0;
    q.push(x);
    while(q.size()){
        int cur=q.front();
        int curd=dist[cur];
        q.pop();
        for(int i=0;i<edge[cur].size();i++){
            int nxt=edge[cur][i];
            if(curd+1<dist[nxt]){
                dist[nxt]=curd+1;
                q.push(nxt);
            }
        }
    }
    
    int chk=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==k){
            chk=1;
            cout<<i<<"\n";
        }
    }
    
    if(chk==0) cout<<-1<<"\n";
    
    
    return 0;
}
