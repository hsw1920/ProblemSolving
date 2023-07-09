#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> maps;
int visited[5][5]={0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

// prev가 0일땐 ok
// 0일때는 파티션을 지난것
bool chk=false;
void dfs(int x, int y, int depth, int prev){
    if(depth==1&&maps[x][y]=='P'&&prev!=0){
        chk=true;
        return ;
    }
    if(depth==2){
        if(maps[x][y]=='P'&&prev!=0){
            chk=true;
        }
        return ;
    }   
    
    // 현재가 파티션이면
    if(maps[x][y]=='X'){
        prev=0;
    }else {
        prev=1;
    }
    for(int s=0;s<4;s++){
        int nx=x+dx[s];
        int ny=y+dy[s];
        if(nx>=0&&ny>=0&&nx<5&&ny<5&&visited[nx][ny]==0){
            visited[nx][ny]=1;
            dfs(nx,ny,depth+1,prev);
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int k=0;k<5;k++){
        // init
        chk=false;
        maps.clear();
        for(int i=0;i<5;i++){
            maps.push_back(places[k][i]);
            for(int j=0;j<5;j++){
                visited[i][j]=0;
            }
        }
            
             
        // dfs
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(maps[i][j]=='P'&&visited[i][j]==0){
                    visited[i][j]=1;
                    dfs(i,j,0,0);
                    
                    for(int q=0;q<5;q++)
                        for(int w=0;w<5;w++)
                            visited[q][w]=0;
                    
                }
            }
        }
        if(chk){
            answer.push_back(0);
        }else{
            answer.push_back(1);
        }
    }
    
    return answer;
}