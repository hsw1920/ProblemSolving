//
//  main.cpp
//  12869
//
//  Created by 홍승완 on 2022/07/18.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int a[3],n, visited[61][61][61];
int dx[6][3]{
    {9,3,1},
    {9,1,3},
    {1,3,9},
    {1,9,3},
    {3,1,9},
    {3,9,1}
};
struct A{
    int a,b,c;
};
queue<A>q;

int solve(int a, int b, int c){
    visited[a][b][c]=1;
    q.push({a,b,c});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]){ // 0이 아니라면 break;
            break;
        }
        for(int i=0;i<6;i++){
            int na= max(0,a-dx[i][0]);
            int nb= max(0,b-dx[i][1]);
            int nc= max(0,c-dx[i][2]);
            if(visited[na][nb][nc])continue;
            visited[na][nb][nc] = visited[a][b][c]+1;
            q.push({na,nb,nc});
        }
    }
    return visited[0][0][0]-1; // 최초가 1이므로 -1해줘야함
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<< solve(a[0],a[1],a[2])<<"\n";
    return 0;
}
