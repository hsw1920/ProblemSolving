//
//  main.cpp
//  12851
//
//  Created by 홍승완 on 2022/03/17.
//

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//int n,k;
//int vis[100001];
//int cnt=0;
//int t;
//void bfs(){
//    queue<pair<int,int>>q;
//    q.push({n,0});
//    while(!q.empty()){
//        int x=q.front().first;
//        int y=q.front().second;
//        q.pop();
//        vis[x]=1;
//        if(x==k && t==y)
//            cnt++;
//        if(cnt==0 && x==k){
//            t=y;
//            cnt++;
//        }
//        if(x+1<=100000 && vis[x+1]==0)
//            q.push({x+1,y+1});
//        if(x-1>=0 && vis[x-1]==0)
//            q.push({x-1,y+1});
//        if(2*x<=100000 && vis[2*x]==0)
//        q.push({2*x,y+1});
//    }
//}
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin>>n>>k;
//    bfs();
//    cout<<t<<"\n"<<cnt;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n,k;
int visited[100001]={0,};
int cnt=0;
int t=1e9;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // x-1 or x+1 or 2x
    cin>>n>>k;
    // 시간, 방법 수
    
    queue<pair<int,int>>q;
    q.push({n,0});
    while(q.size()){
        int x=q.front().first; // 현재위치
        int y=q.front().second; // 현재시간
        q.pop();
        visited[x]=1;
        if(x==k&&t==y){
            cnt++;
        }
        else if(x==k&&cnt==0){
            cnt=1;
            t=y;
        }
        
        //next
        if(x-1>=0&&visited[x-1]==0){
            q.push({x-1,y+1});
        }
        if(x+1<=100000&&visited[x+1]==0){
            q.push({x+1,y+1});
        }
        if(x*2<=100000&&visited[x*2]==0){
            q.push({x*2,y+1});
        }
        
    }
    cout<<t<<"\n"<<cnt<<"\n";
    return 0;
}
