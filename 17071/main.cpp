//
//  main.cpp
//  17071
//
//  Created by 홍승완 on 2022/07/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n,k;
int visited[500001][2];// 홀짝시간

// 나는 순간이동+걷기
// 동생은 걷기만
// 나와 동생 모두 움직임!

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    visited[n][0]=1;
    queue<pair<int,int>>q;
    q.push({n,0});
    while(q.size()){
        int cur=q.front().first;
        int t=q.front().second;
        int sister=k+t*(t+1)/2;
        q.pop();
        if(sister>500000){
            cout<<-1<<"\n";
            break;
        }
        if(cur==sister||visited[sister][t%2]==1){
            cout<<t<<"\n";
            break;
        }
        for(int next: {cur-1,cur+1,cur*2}){
            if(next>=0&&next<=500000&&visited[next][(t+1)%2]==0){
                q.push({next,t+1});
                visited[next][(t+1)%2]=1;
            }
        }
        
    }
    
    return 0;
}

