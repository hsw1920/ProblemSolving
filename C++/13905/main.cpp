//
//  main.cpp
//  13905
//
//  Created by 홍승완 on 2023/04/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,s,e,h1,h2,k;
vector<pair<int,pair<int,int>>>edge;
int set[100001];

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
    
    cin>>n>>m;
    cin>>s>>e;
    for(int i=0;i<m;i++){
        cin>>h1>>h2>>k;
        edge.push_back({k,{h1,h2}});
    }
    
    for(int i=0;i<=n;i++)set[i]=i;
    sort(edge.begin(),edge.end(),greater<pair<int,pair<int,int>>>());
    
    int res=0;
    for(int i=0;i<m;i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            if(find(s)==find(e)){
                res=edge[i].first;
                break;
            }
        }
    }
    cout<<res<<"\n";
    
    return 0;
}
