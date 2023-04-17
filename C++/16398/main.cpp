//
//  main.cpp
//  16398
//
//  Created by 홍승완 on 2023/04/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[1001][1001];
int set[1001];
vector<pair<int,pair<int,int>>>edge;

int find(int x){
    if(x==set[x])return x;
    return set[x]=find(set[x]);
}

void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    set[y]=x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            if(i!=j){
                edge.push_back({map[i][j],{i,j}});
            }
        }
    }
    for(int i=0;i<=n;i++) set[i]=i;
    long long res=0;
    sort(edge.begin(),edge.end());
    for(int i=0;i<edge.size();i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            res+=edge[i].first;
            Union(x,y);
        }
    }
    
    cout<<res<<"\n";
    
    return 0;
}
