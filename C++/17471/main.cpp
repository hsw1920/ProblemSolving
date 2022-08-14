//
//  main.cpp
//  17471
//
//  Created by 홍승완 on 2022/07/28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,k;
int num[11];
int visited[11];
bool chk[11];
int res=1e9;
vector<int> g[11];

void dfs(int x, int cnt){
    
    for(int i=0;i<g[x].size();i++){
        if(chk[g[x][i]]==false&&visited[g[x][i]]==cnt){
            chk[g[x][i]]=true;
            dfs(g[x][i],cnt);
        }
    }
}

bool chking(){

    for(int i=1;i<=n;i++){
        if(visited[i]==1){
            chk[i]=true;
            dfs(i,1);
            break;
        }
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            chk[i]=true;
            dfs(i,0);
            break;
        }
    }

    for(int i=1;i<=n;i++){
        if(chk[i]==false) return false;
    }
    return true;
}

void go(int cnt){
    if(cnt==n){
        for(int i=1;i<=n;i++)chk[i]=false;
        if(chking()){
            int sum1=0, sum2=0;
            for(int i=1;i<=n;i++){
                if(visited[i]==1){
                    sum1+=num[i];
                }else{
                    sum2+=num[i];
                }
            }
            int result = abs(sum1-sum2);
            if(res>result)  res=result;
        }
        return;
    }
    visited[cnt+1]=1;
    go(cnt+1);
    visited[cnt+1]=0;
    go(cnt+1);
}

int main(){

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>num[i];
    }

    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            int tmp;
            cin>>tmp;
            g[i].push_back(tmp);
        }
    }

    go(0);
    if(res==1e9) res=-1;
    cout<<res;

    return 0;
}
