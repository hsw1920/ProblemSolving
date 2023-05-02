//
//  main.cpp
//  17472
//
//  Created by 홍승완 on 2023/05/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int maps[11][11]; // 땅 1, 바다 0
int visited[11][11];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cnt=1;
int set[7];
int u,v,w;
vector<pair<int,pair<int,int>>>edge;

void dfs(int x, int y, int cnt){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&visited[xx][yy]==0&&maps[xx][yy]==1){
            visited[xx][yy]=1;
            maps[xx][yy]=cnt;
            dfs(xx,yy,cnt);
        }
    }
}

void getEdge(int x, int y, int u){
    for(int i=0;i<4;i++){
        int cur=u;
        int xx=x+dx[i];
        int yy=y+dy[i];
        int dist=0;
        while(maps[xx][yy]!=cur&&xx>=0&&yy>=0&&xx<n&&yy<m){
            if(maps[xx][yy]!=0){
                v=maps[xx][yy];
                if(dist>1){
                    edge.push_back({dist,{u,v}});
                }
                break;
            }
            dist++;
            xx+=dx[i];
            yy+=dy[i];
        }
    }
}

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
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0&&maps[i][j]==1){
                maps[i][j]=cnt;
                dfs(i,j,cnt);
                cnt++;
            }
        }
    }
    // set 세팅
    for(int i=0;i<cnt;i++)set[i]=i; // 최대 섬이 6개임
    // 완전탐색으로 edge 수집
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]!=0){
                u=maps[i][j];
                getEdge(i,j,u);
            }
        }
    }
    
    sort(edge.begin(),edge.end());
    int res=0;
    int num=0;
    for(int i=0;i<edge.size();i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x,y);
            res+=edge[i].first;
            num++;
        }
    }
    
    if(num!=cnt-2){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<res<<"\n";

    return 0;
}
