//
//  main.cpp
//  9328
//
//  Created by 홍승완 on 2022/04/09.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int t;
int h,w;
char map[104][104];
int vis[104][104]={0,};
int doc[104][104]={0,};//문서의 방문처리
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int key[26]={0,};
int cnt=0;
// . 빈공간 | * 벽 | $ 훔쳐야될 문서 | 대문자알파벳 문 | 소문자알파벳 열쇠

void bfs(){
    queue<pair<int,int>>q;
    vis[0][0]=1;
    q.push({0,0});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&yy>=0&&xx<=h+1&&yy<=w+1
               &&map[xx][yy]!='*'&&vis[xx][yy]==0){
                //일단 벽이랑 방문했던곳이 아닐때
                //대문자일때
                if(map[xx][yy]>='A'&&map[xx][yy]<='Z'){
                    //key가 있으면 push
                    if(key[map[xx][yy]-'A']==1){
                        vis[xx][yy]=1;
                        q.push({xx,yy});
                    }
                }
                //소문자일때 -> vis초기화도 해주어야 함
                // 갈 수 있는영역이 달라졌기 때문
                else if(map[xx][yy]>='a'&&map[xx][yy]<='z'){
                    if(key[map[xx][yy]-'a']==0){
                        key[map[xx][yy]-'a']=1;
                        //vis 초기화
                        for(int ii=0;ii<h+2;ii++){
                            for(int jj=0;jj<w+2;jj++)
                                vis[ii][jj]=0;
                        }
                    }
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }
                //문서일때
                else if(map[xx][yy]=='$'){
                    //처음 획득한 문서일 때
                    if(doc[xx][yy]==0){
                        doc[xx][yy]=1;
                        vis[xx][yy]=1;
                        cnt++;
                        q.push({xx,yy});
                    }
                    //이미 획득한 문서일 때
                    else{
                        vis[xx][yy]=1;
                        q.push({xx,yy});
                    }
                }
                //빈 칸일때  -> '.'일 때
                else if(map[xx][yy]=='.'){
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        //init
        cnt=0;
        for(int i=0;i<=26;i++)
            key[i]=0;
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++)
                doc[i][j]=0;
        }
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++)
                vis[i][j]=0;
        }
        cin>>h>>w;
        string str;
        for(int i=0;i<=h+1;i++){
            if(i>=1&&i<=h){
                cin>>str;
                map[i][0]='.';
                for(int j=1;j<=w;j++){
                    map[i][j]=str[j-1];
                }
                map[i][w+1]='.';
            }
            else{
                for(int j=0;j<=w+1;j++)
                    map[i][j]='.';
            }
        }
        cin>>str;
        //열쇠가 없는게 아니라면 열쇠를 저장
        if(str[0]!=0){
            int k=str.size();
            for(int i=0;i<k;i++){
                key[str[i]-'a']=1;
            }
        }

        // 열쇠 먹으면 vis초기화 해줘야함
        // .과 $와 소문자알파벳일때만 움직일 수 있음
        // 대문자알파벳은 해당키가 없으면 못움직임
        bfs();// 0,0 가장자리 빈칸에서 시작
        cout<<cnt<<"\n"; // 문서갯수 출력
    }
    
    return 0;
}
