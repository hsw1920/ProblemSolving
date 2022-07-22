//
//  main.cpp
//  15684
//
//  Created by 홍승완 on 2022/07/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n,m,h;// 세로,가로선,개수
int a,b; //
int arr[31][11];
int res=1e9;

bool isVal(){
    for(int j=1;j<=n;j++){
        int col=j;
        for(int i=1;i<=h;i++){
            // 오른쪽으로이동
            if(arr[i][col])
                col++;
            // 왼쪽으로이동
            else if(arr[i][col-1])
                col--;
            // 아무일도 안일어남. 아래로이동
        }
        // j번세로선 결과가 j번이 아니면 false
        if(col!=j){
            return false;
        }
    }
    return true;
}

void dfs(int depth, int cnt){
    if(depth==cnt){
        if(isVal()){
            cout<<depth<<"\n";
            exit(0);
        }
        return;
    }
    for(int j=1;j<n;j++){
        for(int i=1;i<=h;i++){
            if(arr[i][j]||arr[i][j-1]||arr[i][j+1])continue;
            arr[i][j]=1;
            dfs(depth,cnt+1);
            arr[i][j]=0;
            while(!arr[i][j-1]&&!arr[i][j+1])i++;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>h;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        arr[a][b]=1;
    }
    for(int i=0;i<4;i++){
        dfs(i,0);
    }
    
    if(res==1e9)res=-1;
    
    cout<<res<<"\n";
    return 0;
}
