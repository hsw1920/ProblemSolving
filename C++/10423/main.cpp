//
//  main.cpp
//  10423
//
//  Created by 홍승완 on 2023/04/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k,u,v,w;
int set[1001];
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
    
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++)set[i]=i;
    for(int i=0;i<k;i++){
        // 발전소 설치된 도시 번호
        int tmp;
        cin>>tmp;
        set[tmp]=0;
    }
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge.push_back({w,{u,v}});
    }
    sort(edge.begin(),edge.end());
    
    int res=0;
    for(int i=0;i<edge.size();i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x, y);
            res+=edge[i].first;
            
        }
    }
    cout<<res<<"\n";
    return 0;
}
