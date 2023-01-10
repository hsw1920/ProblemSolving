//
//  main.cpp
//  15663
//
//  Created by 홍승완 on 2023/01/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int>v;
int arr[10];
int visited[10];

void dfs(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<v[arr[i]]<<" ";
        }
        cout<<"\n";
        return;
    }
    int tmp=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0&&tmp!=v[i]){
            arr[k]=i;
            tmp=v[i];
            visited[i]=1;
            dfs(k+1);
            visited[i]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    dfs(0);
    return 0;
}

