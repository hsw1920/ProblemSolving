//
//  main.cpp
//  1068
//
//  Created by 홍승완 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,k;
int rNode;
vector<int>tree[50];
int cnt=0;
void deleteNode(int x){
    for(int i=0;i<tree[x].size();i++){
        deleteNode(tree[x][i]);
    }
    while(tree[x].size())tree[x].pop_back();
}
void dfs(int x){
    if(tree[x].size()==0){
        cnt++;
        return;
    }
    for(int i=0;i<tree[x].size();i++){
        dfs(tree[x][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int tmp;
    
    for(int i=0;i<n;i++){
        cin>>tmp;
        // 루트노드
        if(tmp==-1){
            rNode=i;
            continue;
        }
        tree[tmp].push_back(i);
    }
    cin>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<tree[i].size();j++){
            if(tree[i][j]==k){
                tree[i].erase(tree[i].begin()+j); 
                deleteNode(k);
                break;
            }
        }
    }
    dfs(rNode);
    
    if(k==rNode)cnt=0;
    cout<<cnt<<"\n";
    return 0;
}
