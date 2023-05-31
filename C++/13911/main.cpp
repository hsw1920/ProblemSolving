//
//  main.cpp
//  13911
//
//  Created by 홍승완 on 2023/05/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pint;
int V,E,u,v,w,M,x,S,y;
vector<pint>edge[10001];
int dist[10001];
bool mac[10001];
bool star[10001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>V>>E;
    for(int i=1;i<=V;i++){
        dist[i]=1e9;
    }
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    cin>>M>>x;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        mac[tmp]=1; // 맥세권
    }
    cin>>S>>y;
    for(int i=0;i<S;i++){
        int tmp;
        cin>>tmp;
        star[tmp]=1; // 스세권
    }
    
    return 0;
}
