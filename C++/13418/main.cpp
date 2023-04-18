//
//  main.cpp
//  13418
//
//  Created by 홍승완 on 2023/04/18.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,a,b,c;
vector<pair<int,pair<int,int>>>edge;
int set[1001];

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

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    
    // 입구
    int startW, s; // s는 항상 1번 건물
    cin>>a>>s>>startW;
//    edge.push_back({startW,{a,s}});
    
    
    // 나머지
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    for(int i=0;i<=n;i++)set[i]=i;
    set[s]=0;
    sort(edge.begin(),edge.end());
    int resmax;
    if(startW==0) resmax=1;
    else resmax=0;
    
    for(int i=0;i<edge.size();i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            if(edge[i].first==0)resmax+=1;
        }
    }
    int resmin;
    if(startW==0) resmin=1;
    else resmin=0;
    for(int i=0;i<=n;i++)set[i]=i;
    set[s]=0;
    sort(edge.begin(),edge.end(),greater<pair<int,pair<int,int>>>());
    for(int i=0;i<edge.size();i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            if(edge[i].first==0)resmin+=1;
        }
    }
    cout<< resmax*resmax - resmin*resmin <<"\n";
    
    return 0;
}
