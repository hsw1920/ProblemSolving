//
//  main.cpp
//  15686
//
//  Created by 홍승완 on 2022/07/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n,m;
int maps[51][51];

vector<pair<int,int>>v; // 치킨집의 좌표
int res=1e9;
void solve(stack<pair<int,int>>s){
    vector<pair<int,int>>v;
    // m개 좌표가 넣어진 스택s를
    while(s.size()){
        int x=s.top().first;
        int y=s.top().second;
        v.push_back({x,y});
        s.pop();
    }
    int pres=0;
    //각 집에서 치킨거리(min)를 구해서 저장해놓음
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(maps[i][j]==1){
                int ppres=1e9;
                for(int k=0;k<v.size();k++){
                    ppres=min(ppres,abs(i-v[k].first)+abs(j-v[k].second));
                }
                pres+=ppres;
            }
        }
    }
    res=min(res,pres);
}

void select(int x, stack<pair<int,int>>s){
    if(s.size()==m){
        solve(s);
        return;
    }
    for(int i=0;i<x;i++){
        s.push({v[i].first,v[i].second});
        select(i, s);
        s.pop();
    }
}

int main() {
    // 각 집의 치킨거리는 치킨집과의 거리의 최솟값
    // 도시의 치킨거리는 모든 집의 치킨거리의 최솟값의 합
    // 빈칸0 집1 치킨집2
    // M개의 치킨집 빼고 모두 폐업시켜야함.
    // 도시의 치킨거리를 최소로하여 폐업시키고 도시치킨거리의 최솟값 구해라
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
            if(maps[i][j]==2){
                v.push_back({i,j}); // 치킨집 좌표저장
                maps[i][j]=0;
            }
        }
    }
    // 치킨집을 m개 고름
    stack<pair<int,int>>s;
    for(int i=0;i<v.size();i++){
        s.push({v[i].first,v[i].second});
        select(i,s);
        s.pop();
    }
    // 각 m개의 치킨집 쌍에서 완전탐색을 통해 치킨거리를 구하여 최솟값들 구함
    cout<<res<<"\n";

    return 0;
}
