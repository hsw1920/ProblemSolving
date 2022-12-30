//
//  main.cpp
//  4485
//
//  Created by 홍승완 on 2022/12/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int maps[126][126];
int dist[126][126];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
typedef pair<int,int> pint;
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=1e9;
            cin>>maps[i][j];
        }
    }
}

void dijkstra(){
    priority_queue<pair<int,pint>,vector<pair<int,pint>>,greater<pair<int,pint>>>pq;
    dist[0][0]=maps[0][0];
    pq.push({dist[0][0],{0,0}});
    
    while(pq.size()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            int nxt = maps[xx][yy];
            
            if(xx>=0&&xx<n&&yy>=0&&yy<n) {
                int before = dist[xx][yy];
                int cur=dist[x][y]+nxt;
                if(before>cur){
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
    int k=1;
    while(1){
        cin>>n;
        if(n==0)break;
        init();
        dijkstra();
        cout<<"Problem "<<k++<<": "<<dist[n-1][n-1]<<"\n";
        
    }
    return 0;
}
