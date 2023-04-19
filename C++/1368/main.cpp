//
//  main.cpp
//  1368
//
//  Created by 홍승완 on 2023/04/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,set[301],maps[301][301],w[301];
vector<pair<int,pair<int,int>>>edge;

int find(int x){
    if(set[x]==x)return x;
    return set[x]=find(set[x]);
}

void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x<y)set[y]=x;
    else set[x]=y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        edge.push_back({w[i],{0,i}});
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>maps[i][j];
            if(j>i)edge.push_back({maps[i][j],{i,j}});
        }
    }
    
    sort(edge.begin(),edge.end());
    
    for(int i=0;i<=n;i++)set[i]=i;
    int res = 0;
    
    for(int i=0;i<edge.size();i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            res+=edge[i].first;
        }
    }
    
    cout<<res<<"\n";
    
    return 0;
}
