//
//  main.cpp
//  16946
//
//  Created by 홍승완 on 2022/04/06.
//

#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int n,m;
//map을 그룹화해서 숫자랑 그룹번호를 같이 저장한다
pair<int,int> map[1001][1001];
// first가 숫자, second가 그룹번호
int groupNum=0;
int d=0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

//0일때 그룹번호를 지정하도록 dfs
void dfs(int x,int y){
    d++;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&map[xx][yy].second!=groupNum
           &&map[xx][yy].first==0){
            map[xx][yy].second=groupNum;
            dfs(xx,yy);
        }
    }
}
void dfs2(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&map[xx][yy].second==groupNum
           &&map[xx][yy].first==0){
            map[xx][yy].first=d;
            dfs2(xx,yy);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            map[i][j]={str[j]-'0',0};
        }
    }
    // n*m에서 1인 부분만 0으로 바꾸고
    // dfs로 0인부분만 카운팅후 다시 1로 바꿈
    // vis는 계속 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            d=0;
            if(map[i][j].first==0){
                groupNum++;
                // 그룹의 번호를 지정함
                map[i][j].second=groupNum;
                dfs(i,j);
                //d가 해당 그룹의 원소의 갯수
                //각 그룹의 라벨링을 진행
                map[i][j].first=d;
                dfs2(i,j);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j].second==0){
                set<pair<int,int>>s;
                for(int q=0;q<4;q++){
                    int xx=i+dx[q];
                    int yy=j+dy[q];
                    if(xx>=0&&yy>=0&&xx<n&&yy<m&&map[xx][yy].second!=0){
                        s.insert({map[xx][yy].first,map[xx][yy].second});
                    }
                }
                int res=1;
                for(auto &k:s){
                    res+=k.first;
                }
                cout<<res%10;
            }
            else
               cout<<0;
        }
        cout<<"\n";
    }
    
    return 0;
}
