//
//  main.cpp
//  2042
//
//  Created by 홍승완 on 2023/04/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n,m,k;
vector<long long>tree;
long long a,b,c;

void makeTree(int i){
    while(i){
        tree[i/2]+=tree[i];
        i--;
    }
}

void changeVal(long long idx, long long c){
    //b번째 수를 c로 바꿈
    long long diff=c-tree[idx];
    while(idx){
        tree[idx]+=diff;
        idx/=2;
    }
}

long long getSum(long long b, long long c){
    long long psum=0;
    while(b<=c){
        if(b%2==1)psum+=tree[b++];
        if(c%2==0)psum+=tree[c--];
        b/=2;
        c/=2;
    }
    return psum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    
    int h=ceil(log2(n));
    int treeSize=1<<(h+1);
    int startIdx=treeSize/2;
    tree.resize(treeSize+1);
    
    for(int i=startIdx;i<startIdx+n;i++){
        cin>>tree[i];
    }
    
    makeTree(treeSize-1);
    
    for(int i=0;i<m+k;i++){
        cin>>a>>b>>c;
        if(a==1){
            changeVal(startIdx+b-1,c);
        }else {
            cout<<getSum(startIdx+b-1,startIdx+c-1)<<"\n";
        }
    }
 
    return 0;
}
