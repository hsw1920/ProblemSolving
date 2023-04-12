//
//  main.cpp
//  1043
//
//  Created by 홍승완 on 2023/04/12.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,a,b,num[51],maps[51][51],party[51];

int find(int a){
    if(num[a]==a)return a;
    return num[a]=find(num[a]);
}

void makeUnion(int a, int b){
    a=find(a);
    b=find(b);
    if(a>b) num[a]=b;
    else num[b]=a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    cin>>a;

    for(int i=1;i<=n;i++)num[i]=i;
    for(int i=0;i<a;i++){
        cin>>b;
        makeUnion(num[b], 0);
    }
    for(int i=0;i<m;i++){
        cin>>a;
        party[i]=a;
        for(int j=0;j<a;j++){
            cin>>b;
            maps[i][j]=b;
            
        }
        for(int j=0;j<a;j++){
            for(int k=0;k<a;k++){
                makeUnion(maps[i][j], maps[i][k]);
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<party[i];j++){
            makeUnion(maps[i][j], maps[i][j]);
        }
    }
    int res=0;
    for(int i=0;i<m;i++){
        int cnt=0;
        for(int j=0;j<party[i];j++){
            if(num[maps[i][j]]==0)cnt=1;
        }
        if(cnt==0) res++;
    }

    cout<<res<<"\n";
    return 0;
}
