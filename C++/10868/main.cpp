//
//  main.cpp
//  10868
//
//  Created by 홍승완 on 2023/06/11.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,a,b;
vector<long long>tree;

void makeTree(int i){
    while(i){
        tree[i/2]=min(tree[i/2],tree[i]);
        i--;
    }
}

long long getMinValue(int s, int e){
    long long minVal=1e18;
    while(s<=e){
        if(s%2==1){
            minVal=min(minVal,tree[s++]);
        }
        if(e%2==0){
            minVal=min(minVal,tree[e--]);
        }
        s/=2;
        e/=2;
    }
    return minVal;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    int h=ceil(log2(n));
    int treeSize=1<<(h+1);
    int startIdx=treeSize/2;
    tree.resize(treeSize+1);
    for(int i=0;i<=startIdx+n;i++){
        tree[i]=1e18;
    }
    
    for(int i=startIdx;i<startIdx+n;i++){
        cin>>tree[i];
    }
    makeTree(treeSize-1);
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<getMinValue(startIdx+a-1,startIdx+b-1)<<"\n";
    }
    

    return 0;
}
