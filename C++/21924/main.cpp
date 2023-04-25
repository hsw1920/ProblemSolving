//
//  main.cpp
//  21924
//
//  Created by 홍승완 on 2023/04/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pint;
int n,m,a,b,c;
vector<pair<int,pint>>edge;
int set[100001];

int find(int x){
    if(set[x]==x)return x;
    return set[x]=find(set[x]);
}

void Union(int x, int y){
    int a=find(x);
    int b=find(y);
    if(a<b)set[b]=a;
    else set[a]=b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    
    // 건물개수 n, 간선 m
    long long sum=0;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        sum+=c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<=n;i++)set[i]=i;
    long long cnt=1,res=0;
    for(int i=0;i<m;i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            cnt++;
            res+=edge[i].first;
            if(cnt==n){
                cout<<sum-res<<"\n";
                return 0;
            }
        }
    }
    cout<<"-1"<<"\n";
    
    return 0;
}
