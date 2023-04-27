//
//  main.cpp
//  1185
//
//  Created by 홍승완 on 2023/04/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,p,s,e,l,c;
int set[10001];
int pay[10001],psum[10001];
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
// 시작나라를 정할 수 있음
// 시작-> 모든나라 여행, 시작나라로 돌아와야함
// n-1개의 길만을 남겨야함 -> 싸이클X -> mst일 수 밖에 없음
// 시작나라는 방문을 2번하므로 가장 최소비용인 나라를 지정해야함

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>p;
    int startIdx, tmp=1e9;
    
    for(int i=1;i<=n;i++){
        set[i]=i;
        cin>>pay[i];
        if(tmp>pay[i]){
            tmp=pay[i];
            startIdx=i; // 시작나라 설정
        }
    }
    int visit_cost=pay[startIdx];
    for(int i=0;i<p;i++){
        cin>>s>>e>>l;
        edge.push_back({l*2+pay[s]+pay[e],{s,e}});
    }
    sort(edge.begin(),edge.end());
    int load_cost=0;
    for(int i=0;i<p;i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            load_cost+=edge[i].first;
        }
    }
    int res=visit_cost+load_cost;
    
    cout<<res<<"\n";
    return 0;
}
