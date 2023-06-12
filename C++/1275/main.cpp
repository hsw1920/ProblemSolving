//
//  main.cpp
//  1275
//
//  Created by 홍승완 on 2023/06/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n,q,x,y,a,b;
vector<long long>tree;

void makeTree(long long idx){
    while(idx){
        tree[idx/2]+=tree[idx];
        idx--;
    }
}

long long getSum(long long s, long long e){
    long long sum=0;
    while(s<=e){
        if(s%2==1)sum+=tree[s++];
        if(e%2==0)sum+=tree[e--];
        s/=2;
        e/=2;
    }
    return sum;
}

void changeVal(long long idx, long long val){
    long long diff=val-tree[idx];
    while(idx){
        tree[idx]+=diff;
        idx/=2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>q;
    long long h=ceil(log2(n));
    long long treeSize=1<<(1+h);
    long long startIdx=treeSize/2;
    tree.resize(treeSize+1);
    for(long long i=0;i<n;i++){
        cin>>tree[startIdx+i];
    }
    makeTree(treeSize-1);
    for(long long i=0;i<q;i++){
        cin>>x>>y>>a>>b;
        // x~y까지의 합을 구하라, a번째수를 b로 바꾸어라
        if(x>y)
            swap(x,y);
        cout<<getSum(startIdx+x-1,startIdx+y-1)<<"\n";
    
        changeVal(startIdx+a-1,b);
    }
    
    return 0;
}
