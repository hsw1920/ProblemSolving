//
//  main.cpp
//  5014
//
//  Created by 홍승완 on 2022/03/14.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
//총 f층, 스타트링크는 G층 강호는 s층으로 가고
//엘베타고 g층으로 가야함  u or d 버튼 2개
// 현재s층 -> g층
int F,S,G,U,D;
int res=1e9;

void bfs(int s){
    queue<pair<int,int>>q;
    int visit[1000001]={0,};
    q.push({s,0});
    visit[s]=1;
    while(!q.empty()){
        int k=q.front().first;
        int w=q.front().second;
        if(k==G){
            res=w;
            break;
        }
        q.pop();
        if(k+U<=F && visit[k+U]==0){
            visit[k+U]=1;
            q.push({k+U,w+1});
        }
        if(k-D>0 && visit[k-D]==0){
            visit[k-D]=1;
            q.push({k-D,w+1});
        }
    }
}


int main(){
    
    cin>>F>>S>>G>>U>>D;
    bfs(S);
    if(res==1e9)
        cout<<"use the stairs";
    else cout<<res;
 
    return 0;
}
