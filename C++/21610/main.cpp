//
//  main.cpp
//  21610
//
//  Created by 홍승완 on 2022/10/27.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int maps[51][51];
int d[101],s[101];
//           idx는 1부터
int dx[9]={0,0,-1,-1,-1,0,1,1,1};
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
int visited[51][51];
vector<pair<int,int>>cloud;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
    for(int i=0;i<m;i++){
        cin>>d[i]>>s[i];
    }
    // init 구름만들기
    cloud.push_back({n-1,0});
    cloud.push_back({n-1,1});
    cloud.push_back({n-2,0});
    cloud.push_back({n-2,1});
    
    for(int q=0;q<m;q++){
        
        for(int i=0;i<cloud.size();i++){
            // d,s 만큼 이동
            cloud[i].first = (cloud[i].first+dx[d[q]]*(s[q]%n) + n) % n;
            cloud[i].second = (cloud[i].second+dy[d[q]]*(s[q]%n) + n) % n;
            
            // chk
            visited[cloud[i].first][cloud[i].second] = 1;
            
            // 구름있는칸에 +1
            maps[cloud[i].first][cloud[i].second]+=1;
        }
        
        for(auto k :cloud) {

            // 구름있는 칸 대각선보고 ++
            if(k.first-1>=0&&k.second-1>=0 && maps[k.first-1][k.second-1]>0){
                maps[k.first][k.second]++;
            }
            if(k.first-1>=0&&k.second+1<n && maps[k.first-1][k.second+1]>0){
                maps[k.first][k.second]++;
            }
            if(k.first+1<n&&k.second-1>=0 && maps[k.first+1][k.second-1]>0){
                maps[k.first][k.second]++;
            }
            if(k.first+1<n&&k.second+1<n && maps[k.first+1][k.second+1]>0){
                maps[k.first][k.second]++;
            }
        }
        // 구름 전부 없애기
        while(cloud.size())cloud.pop_back();
        
        // 구름 없는 칸에서 2이상인곳 -2하고 구름 만들기
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && maps[i][j]>=2){
                    maps[i][j]-=2;
                    cloud.push_back({i,j});
                }
            }
        }
        
        //visit 초기화
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
    
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res += maps[i][j];
        }
    }
    cout<<res<<"\n";
    
    
    return 0;
}
