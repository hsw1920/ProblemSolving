//
//  main.cpp
//  2660
//
//  Created by 홍승완 on 2022/03/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

// 간단한 플로이드와샬 알고리즘 문제였다...

using namespace std;
int n,a,b;
int v[51][51];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j)v[i][j]=0;
            else v[i][j]=1e9;
        }
    }
    while(1){
        cin>>a>>b;
        if(a==-1&&b==-1)
            break;
        v[a][b]=1;
        v[b][a]=1;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cout<<v[i][j];
//        }
//        cout<<"\n";
//    }
    int cnt[51]={0,};
    for(int i=1;i<=n;i++){
        cnt[i]=*max_element(v[i]+1, v[i]+n+1);
        //cout<<cnt[i]<<"\n";
    }
    int minCnt=*min_element(cnt+1,cnt+n+1);
    int k=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==minCnt)k++;
    }
    cout<<minCnt<<" "<<k<<"\n";
    for(int i=1;i<=n;i++){
        if(cnt[i]==minCnt)
            cout<<i<<" ";
    }
    
    
    return 0;
}
