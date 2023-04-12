//
//  main.cpp
//  16562
//
//  Created by 홍승완 on 2023/04/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k,v,w;
int arr[10001],cost[10001];

int find(int a){
    if(arr[a]==a)
        return a;
    return arr[a]=find(arr[a]);
}

void unions(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(cost[a]>=cost[b])
            arr[a]=b;
        else arr[b]=a;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        arr[i]=i;
        cin>>cost[i];
    }
    for(int i=0;i<m;i++){
        cin>>v>>w;
        unions(v,w);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        int cur=find(i);
        if(cur!=find(0)){
            res+=cost[cur];
            unions(0, i);
        }
    }
    if(k>=res) cout<<res<<"\n";
    else cout<<"Oh no\n";
    return 0;
}
