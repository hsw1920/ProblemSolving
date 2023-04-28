//
//  main.cpp
//  9344
//
//  Created by 홍승완 on 2023/04/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t,n,m,p,q,u,v,w;
int set[10001];
vector<pair<int,pair<int,int>>>edge;

int find(int x){
    if(x==set[x])return x;
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
    cin>>t;
    while(t--){
        edge.clear();
        cin>>n>>m>>p>>q;
        // p와 q를 잇는 도로를 건설하는것이 목표
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            edge.push_back({w,{u,v}});
        }
        sort(edge.begin(),edge.end());
        for(int i=0;i<=n;i++)set[i]=i;
        bool chk=false;
        for(int i=0;i<m;i++){
            int x=find(edge[i].second.first);
            int y=find(edge[i].second.second);
            if(x!=y){
                Union(x,y);
                if(((edge[i].second.first==p)&&(edge[i].second.second==q))||((edge[i].second.first==q)&&(edge[i].second.second==p))){
                    chk=true;
                }
            }
        }
        
        if(chk)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
