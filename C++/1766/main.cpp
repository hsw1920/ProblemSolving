//
//  main.cpp
//  1766
//
//  Created by 홍승완 on 2022/04/16.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define pint pair<int,int>
using namespace std;
int n, m;
//진입차수
int d[100001];
int vis[32001];
//순서
vector<int>v[32001];

void topology(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        //진입차수 가장낮고 난이도 쉬운것 뽑음
        if(d[i]==0){
            q.push(i);
            vis[i]=1;
            break;
        }
    }
    while(!q.empty()){
        int next=q.front();
        cout<<next<<" ";
        q.pop();
        //뽑은거관련 진입차수 다빼야함
        int len=v[next].size();
        int tmp=1e9;
        for(int i=0;i<len;i++){
            int target=v[next][i];
            d[target]--;
            if(d[target]==0)
                tmp=min(tmp,target);
        }
        
        //진입할 수 있는 target중에서 가장 작은값 or next다음값부터 시작하면됨
        int start=min(next+1,tmp);
        
        //다뺐으면 진입차수 0인거 넣어야지
        for(int i=start;i<=n;i++){
            //진입차수 가장낮고 난이도 쉬운것 뽑음, 선택안했던거
            if(d[i]==0&&vis[i]==0){
                q.push(i);
                vis[i]=1;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        d[b]++;
        v[a].push_back(b); // b를 뽑으려면 a를 먼저 뽑아야함
    }
    topology();
    return 0;
}
