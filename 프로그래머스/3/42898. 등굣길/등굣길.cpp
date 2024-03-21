#include <bits/stdc++.h>

using namespace std;
long long maps[101][101];
long long visited[101][101];

#define INF 1000000007

long long solution(int m, int n, vector<vector<int>> puddles) {
    long long answer = 0;
    for(auto k: puddles){
        maps[k[1]-1][k[0]-1] = 1; // 못가는곳
    }
    
    for(int i=0;i<n;i++){
        if(maps[i][0]==0) visited[i][0]=1;
        else break;
    } 
        
    for(int i=0;i<m;i++) {
        if(maps[0][i]==0) visited[0][i]=1;
        else break;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(maps[i][j]==0)
                visited[i][j]=(visited[i-1][j]+visited[i][j-1])%INF;
        }
    }
    
    answer = visited[n-1][m-1];
    return answer;
}