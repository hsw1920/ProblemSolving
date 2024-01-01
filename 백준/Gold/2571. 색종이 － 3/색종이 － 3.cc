//
//  main.cpp
//  2571
//
//  Created by 홍승완 on 2024/01/01.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,a,b;
int maps[101][101];
int res=0;
int check(int q,int w,int r,int c){
    for(int i=q;i<=r;i++){
        for(int j=w;j<=c;j++){
            if(maps[i][j]!=1) return -1;
        }
    }
    return (r-q+1)*(c-w+1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>N;
    while(N--){
        cin>>a>>b;
        for(int i=a;i<a+10;i++){
            for(int j=b;j<b+10;j++){
                maps[i][j]=1;
            }
        }
    }
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(maps[i][j]==1){
                for(int r=i;r<=100;r++){
                    for(int c=j;c<=100;c++){
                        if(maps[i][j]!=1)continue;
                        res=max(res,check(i,j,r,c));
                    }
                }
            }
        }
    }
    
    cout<<res<<"\n";
    
    return 0;
}
