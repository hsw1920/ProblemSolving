//
//  main.cpp
//  2665
//
//  Created by 홍승완 on 2022/12/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int maps[51][51];
int dist[51][51];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
typedef pair<int,int> pint;

void dijkstra(){
    dist[0][0]=maps[0][0];
    priority_queue<pair<int,pint>,vector<pair<int,pint>>,greater<pair<int,pint>>>pq;
    pq.push({dist[0][0],{0,0}});
    while(pq.size()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            int nxt = maps[xx][yy];
            if(xx>=0&&xx<n&&yy>=0&&yy<n){
                int cur = dist[x][y]+nxt;
                int prev = dist[xx][yy];
                if(prev>cur){
                    dist[xx][yy]=cur;
                    pq.push({cur,{xx,yy}});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='0')maps[i][j]=1;
            else maps[i][j]=0;
            dist[i][j]=1e9;
        }
    }
    dijkstra();
    cout<<dist[n-1][n-1];
    
    return 0;
}
