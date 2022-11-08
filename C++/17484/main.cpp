//
//  main.cpp
//  17484
//
//  Created by 홍승완 on 2022/11/08.
//

#include <iostream>
#include <algorithm>

using namespace std;
int minNum = 1e9;

int n,m;
int maps[7][7];


void dfs(int h, int k, int num, int idx){
    if(h==n){
        minNum = min(minNum, num+maps[h][k]);
        return;
    }
    for(int i=0;i<3;i++){
        if(idx==i)continue;
        //좌
        if(i==0){
            if(k-1<0)continue;
            dfs(h+1,k-1,num+maps[h][k],i);
        }
        //중
        else if(i==1){
            dfs(h+1,k,num+maps[h][k],i);
        }
        //우
        else {
            if(k+1>=m)continue;
            dfs(h+1,k+1,num+maps[h][k],i);
        }
    }
    
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
    for(int i=0;i<m;i++){
        dfs(0,i,0,-1);
    }
    cout<<minNum<<"\n";
    
    
    return 0;
}
