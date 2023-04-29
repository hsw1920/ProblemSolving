//
//  main.cpp
//  1045
//
//  Created by 홍승완 on 2023/04/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 두 도시 A,B가 도로 x로 연결됨
// C,D가 y로 연결되어있을 때
// 전제: (A,B) < (C,D)이면 x의 우선순위가 y보다 높음
// target: m개의 도로를 가진 도로 집합 중 연결되어있으면서 우선순위가 가장 높은 것을 찾기

int n,m;
char maps[51][51];
int set[51];
int res[51];
vector<pair<int,int>>edge;
vector<pair<int,int>>remain;

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
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
            if(i<j&&maps[i][j]=='Y'){
                edge.push_back({i,j});
            }
        }
    }
    for(int i=0;i<n;i++)set[i]=i;
    sort(edge.begin(),edge.end());
    
    
    
    // 서로 연결되어있는 도로들의 집합을 찾아야함
    // 해당 집합? -> 크루스칼
    // 해당 집합들 중에서 가장 우선순위가 높은것?? -> 연결된 집합중 가장 idx가 낮은것
    int cnt=0;
    if(m>edge.size()){
        cout<<-1<<"\n";
        return 0;
    }
    for(int i=0;i<m;i++){
        int x=find(edge[i].first);
        int y=find(edge[i].second);
        int a=edge[i].first;
        int b=edge[i].second;
        if(x!=y){
            Union(x,y);
            res[a]++;
            res[b]++;
            if(cnt<m-1)
                cnt++;
        }else{
            remain.push_back({a,b});
            if(cnt<m-1)
                cnt++;
        }
        
    }
    
    
    if(cnt<m-1){
        cout<<-1<<"\n";
        return 0;
    }
    else {
        int remain_cnt=m-cnt;
        for(int i=0;i<remain_cnt;i++){
            int a=remain[i].first;
            int b=remain[i].second;
            res[a]++;
            res[b]++;
        }
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
    }
    
    
    
    return 0;
}
