//
//  main.cpp
//  16202
//
//  Created by 홍승완 on 2023/04/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k,x,y;
int set[1001];
vector<pair<int,pair<int,int>>>edge;

int find(int x){
    if(x==set[x])return x;
    return set[x]=find(set[x]);
}

void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x>y)set[x]=y;
    else set[y]=x;
}

// mst비용 -> mst를 이루는 가중치의 합
// 각 턴의 점수 -> 해당 턴에서 찾은 mst의 비용

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        edge.push_back({i,{x,y}});
    }
    sort(edge.begin(),edge.end());
    // mst를 찾고
    // 간선을 지우기
    for(int q=0;q<k;q++){
        for(int i=0;i<=n;i++)set[i]=i;
        int res=0,cnt=1;
        for(int i=q;i<m;i++){
            int a=find(edge[i].second.first);
            int b=find(edge[i].second.second);
            if(a!=b){
                Union(a,b);
                cnt++;
                res+=edge[i].first;
            }
        }
        if(cnt==n){
            cout<<res<<" ";
        }
        else{
            cout<<0<<" ";
        }
    }
    
    return 0;
}
