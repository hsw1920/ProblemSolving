//
//  main.cpp
//  1647
//
//  Created by 홍승완 on 2022/03/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define pint pair<int,int>

using namespace std;

int n, m;
int a,b,c;
//길은 양방향, 마을 분리, 집들이 서로 연결되도록
//마을에는 집이 하나이상, ???
// 최소신장트리?
vector<pair<int,pint>>edge;
int d[100001]={0,};

int find(int x){
    if(d[x]==x)return x;
    return d[x]=find(d[x]);
}

void Union(int a, int b){
    a=find(a);
    b=find(b);
    if(a>b)d[a]=b;
    else d[b]=a;
}

int main() {
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    //초기화
    int res=0;
    for(int i=0;i<=n;i++)
        d[i]=i;
    int k=0;
    sort(edge.begin(),edge.end());
    for(int i=0;i<edge.size();i++){
        int q=edge[i].second.first;
        int w=edge[i].second.second;
        if(find(q)!=find(w)){
            Union(q, w);
            res+=edge[i].first;
            k=max(k,edge[i].first);
        }
    }
    cout<<res-k;
    return 0;
}
