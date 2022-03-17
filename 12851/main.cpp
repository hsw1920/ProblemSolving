//
//  main.cpp
//  12851
//
//  Created by 홍승완 on 2022/03/17.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,k;
int vis[100001];
int cnt=0;
int t;
void bfs(){
    queue<pair<int,int>>q;
    q.push({n,0});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        vis[x]=1;
        if(x==k && t==y)
            cnt++;
        if(cnt==0 && x==k){
            t=y;
            cnt++;
        }
        if(x+1<=100000 && vis[x+1]==0)
            q.push({x+1,y+1});
        if(x-1>=0 && vis[x-1]==0)
            q.push({x-1,y+1});
        if(2*x<=100000 && vis[2*x]==0)
        q.push({2*x,y+1});
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    bfs();
    cout<<t<<"\n"<<cnt;
    return 0;
}
