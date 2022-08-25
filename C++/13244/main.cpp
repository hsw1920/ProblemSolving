//
//  main.cpp
//  13244
//
//  Created by 홍승완 on 2022/08/25.
//

#include <iostream>
#include <vector>

using namespace std;

// 연결됨 -> 모든 노드끼리 서로 도달 가능
// 엣지가 삭제되면, 그래프는 연결x, 즉 어떤 노드끼리는 서로 도달 x
// 두 노드 사이에 엣지가 추가되면 사이클형성됨. a->b로가는 길이 2개이상이면 사이클이있음
// tree인지 graph인지 결정해라

// 그래프는 최대 10개
// n 그래프의 노드수 1~1000개최대
// m 그래프의 간선수, 1000000개 최대
// m개 라인에 a,b로 연결된 간선을 받는다 -> 연결된노드
int t,n,m,a,b;
vector<int>g[1001];
int visited[1001]={0,};
void dfs(int x){
    visited[x]=1;
    for(int i=0;i<g[x].size();i++){
        if(visited[g[x][i]]==0){
            dfs(g[x][i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        // visit초기화
        for(int i=0;i<=n;i++)
            visited[i]=0;
        int cnt=0;
        cin>>n;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        // 1부터 노드 n개까지 dfs로 트리판정
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                dfs(i);
                cnt++;
            }
        }
        // 간선개수는 노드-1 (사이클없는경우)
        // cnt==1이어야 모든 노드가 연결된경우임
        if(m==n-1&&cnt==1){
            cout<<"tree\n";
        }
        else {
            cout<<"graph\n";
        }
    }
    return 0;
}
