//
//  main.cpp
//  16920
//
//  Created by 홍승완 on 2022/04/10.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,p;
int s[10];
char map[1001][1001];
bool check[1001][1001];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<int,int>>qs[10];
int res[10]={0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>p;
    for(int i=1;i<=p;i++)
        cin>>s[i];
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            map[i][j]=str[j];
            if(map[i][j]>='1'&&map[i][j]<='9'){
                res[map[i][j]-'0']++;
                qs[map[i][j]-'0'].push({i,j});
                check[i][j]=1;
            }
        }
    }
    queue<int>player;
    for(int i=1;i<=p;i++){
        player.push(i);
    }
    while(!player.empty()){
        int pl=player.front();
        player.pop();
        //1칸씩 pl번 반복하지않고,
        //한 큐에 s[pl]만큼 bfs로 들어가면
        //다음 큐에서 vis에 막혀서 영역정복이 안 됨!
        //따라서 아래처럼 1칸씩 s[pl]번 반복해야 vis가 다음큐를 방해하지않음
        for(int a=0;a<s[pl];a++){
            int k=qs[pl].size();
            if(k==0)
                break;
            while(k--){
                int x=qs[pl].front().first;
                int y=qs[pl].front().second;
                qs[pl].pop();
                for(int i=0;i<4;i++){
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if(xx>=0&&yy>=0&&xx<n&&yy<m
                       &&map[xx][yy]=='.'){
                        map[xx][yy]=pl+'0';
                        res[pl]++;
                        qs[pl].push({xx,yy});
                    }
                }
            }
            
        }
        if(qs[pl].size()>0)player.push(pl);
    }
    
    for(int i=1;i<=p;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
