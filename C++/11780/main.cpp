//
//  main.cpp
//  11780
//
//  Created by 홍승완 on 2023/01/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int maps[101][101];
int nxt[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n,m,a,b,c;
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            maps[i][j]=1e9;
            if(i==j)maps[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(maps[a][b]>c){
            maps[a][b]=c;
            nxt[a][b]=b;
        }
        
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(maps[i][j]>maps[i][k]+maps[k][j]){
                    maps[i][j]=maps[i][k]+maps[k][j];
                    nxt[i][j]=nxt[i][k];
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(maps[i][j]==1e9)cout<<"0 ";
            else cout<<maps[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    int q=1;
    while(q<=n){
        
        stack<int>st;
        for(int i=1;i<=n;i++){
            int target = i;
            vector<int>v;
            v.push_back(q);
            int go;
            if(nxt[q][i]!=0){
                go=nxt[q][i];
            } else {
                cout<<"0\n";
                continue;
            }
            while(go!=target){
                v.push_back(go);
                go=nxt[go][target];
            }
            v.push_back(go);
            
            cout<<v.size()<<" ";
            for(auto k: v){
                cout<<k<<" ";
            }
            cout<<"\n";
            
        }
        q++;
        
    }
    
    return 0;
}
