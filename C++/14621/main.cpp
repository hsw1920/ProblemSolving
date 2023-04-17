//
//  main.cpp
//  14621
//
//  Created by 홍승완 on 2023/04/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m; // 정점, 간선
int set[1001];

vector<pair<int,pair<int,int>>>edge;
int a,b,c;
char gender[1001];

// 간선은 남,여간 대학만을 연결함
// 경로는 최단거리

int find(int x){
    if(set[x]==x)return x;
    return set[x]=find(set[x]);
}

void Union(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x>y)set[x]=y;
    else set[y]=x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>gender[i];
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(gender[a]!=gender[b]){
            edge.push_back({c,{a,b}});
        }
    }
    for(int i=0;i<=n;i++)set[i]=i;
    sort(edge.begin(),edge.end());
    int res=0;
    for(int i=0;i<edge.size();i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            res+=edge[i].first;
        }
    }

    for(int i=2;i<=n;i++){
        if(find(set[i])!=find(set[i-1])){
            res=-1;
            break;
        }
    }
    cout<<res<<"\n";
    return 0;
}
