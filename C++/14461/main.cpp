//
//  main.cpp
//  14461
//
//  Created by 홍승완 on 2023/05/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,t;
int maps[101][101];
int dx[] = {1, -1,  0,  0,  0,  1,  2,  3,  2,  1,  0, -1, -2, -3, -2, -1};
int dy[] = {0,  0,  1, -1,  3,  2,  1,  0, -1, -2, -3, -2, -1,  0,  1,  2};
typedef pair<int,int> pint;
int dist[101][101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
            dist[i][j]=1e9;
        }
    }
    priority_queue<pint,vector<pint>,greater<pint>>pq;
    int res=1e9;
    pq.push({0,0});
    dist[0][0]=0;
    while(pq.size()){
        int cur=pq.top().second;
        int curd=pq.top().first;
        // int to coord
        int i=pq.top().second/n;
        int j=pq.top().second%n;
        pq.pop();
        //if(dist[i][j]!=curd)continue;
        int toN = (n-i-1)+(n-j-1);
        if(toN<=2){
            res=min(res,curd+toN*t);
        }
        for(int k=0;k<16;k++){
            int ii=i+dx[k];
            int jj=j+dy[k];
            int nxtd=curd+3*t+maps[ii][jj];
            if(ii>=0&&jj>=0&&ii<n&&jj<n&&dist[ii][jj]>nxtd){
                dist[ii][jj]=nxtd;
                // coord to int
                pq.push({nxtd,ii*n+jj});
            }
        }
    }
    
    cout<<res<<"\n";
    return 0;
}

