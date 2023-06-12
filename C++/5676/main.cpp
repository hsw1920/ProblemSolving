//
//  main.cpp
//  5676
//
//  Created by 홍승완 on 2023/06/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,k,a,b;
char op;
vector<int>tree;

void makeTree(int idx){
    while(idx>0){
        if(idx%2==0){
            if(tree[idx]==0||tree[idx+1]==0)
                tree[idx/2]=0;
            else if((tree[idx]<0&&tree[idx+1]>0)||(tree[idx]>0&&tree[idx+1]<0))
                tree[idx/2]=-1;
            else{
                tree[idx/2]=1;
            }
            
        }else{
            if(tree[idx]==0||tree[idx-1]==0)
                tree[idx/2]=0;
            else if((tree[idx]<0&&tree[idx-1]>0)||(tree[idx]>0&&tree[idx-1]<0))
                tree[idx/2]=-1;
            else{
                tree[idx/2]=1;
            }
        }
        idx-=2;
    }
}

void update(int idx, int val){
    if(tree[idx]==0)tree[idx]=val;
    long long diff = tree[idx]*val;
    if(diff==0){
        tree[idx]=val;
    }
    else if(diff<0) {
        diff=-1;
        tree[idx]=val;
    }
    else {
        tree[idx]=val;
        diff=1;
    }
    while(idx>0){
        if(tree[idx/2]==0){
            if(idx%2==0)
                tree[idx/2]=tree[idx]*tree[idx+1];
            else{
                tree[idx/2]=tree[idx]*tree[idx-1];
            }
        }else {
            tree[idx/2]*=diff;
        }
        
        idx/=2;
    }
}

char getMulti(int s, int e){
    int val=1;
    while(s<=e){
        if(s%2==1)val*=tree[s++];
        if(e%2==0)val*=tree[e--];
        s/=2;
        e/=2;
    }
    if(val>0)return '+';
    else if(val<0) return '-';
    return '0';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    while(cin>>n>>k){
        tree.clear();
        int h=ceil(log2(n));
        int treeSize=1<<(h+1);
        int startIdx=treeSize/2;
        tree.resize(treeSize-1);
        fill(tree.begin(),tree.end(),1);
        for(int i=startIdx;i<startIdx+n;i++){
            cin>>tree[i];
        }
        makeTree(treeSize-1);
        for(int i=0;i<k;i++){
            cin>>op>>a>>b;
            if(op=='C'){
                // 변경
                update(startIdx+a-1,b);
            }
            else if(op=='P'){
                // 곱셈
                cout<<getMulti(startIdx+a-1,startIdx+b-1);
            }
        }
        cout<<"\n";
    }

    return 0;
}
