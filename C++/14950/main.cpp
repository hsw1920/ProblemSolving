//
//  main.cpp
//  14950
//
//  Created by 홍승완 on 2023/04/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int set[10001];
int n,m,t,a,b,c,cost;
vector<pair<int,pair<int,int>>>edge;

int find(int x){
    if(set[x]==x)return x;
    return set[x]=find(set[x]);
}

void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x>y)set[x]=y;
    else set[y]=x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>t;
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<=n;i++)set[i]=i;
    int res=0, cost=0;
    for(int i=0;i<m;i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            res+=(edge[i].first+cost);
            cost+=t;
        }
    }
    cout<<res<<"\n";
    return 0;
}
