//
//  main.cpp
//  2243
//
//  Created by 홍승완 on 2023/06/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

int n,a,b,c;
vector<int>tree;
int h=ceil(log2(1000000));
int treeSize=1<<(1+h);
int startIdx=treeSize/2;

void update(int idx, int val){
    int prv=tree[idx];
    tree[idx]=max(0,prv+val);
    int diff=tree[idx]-prv;
    idx/=2;
    while(idx){
        tree[idx]+=diff;
        idx/=2;
    }
}

int query(int cur, int s, int e, int val){
    
    if(val>tree[cur]||val<1)return 0;
    tree[cur]-=1;
    if(s==e)return s;
    int mid=(s+e)/2;
    int diff=tree[cur*2];

    int l=query(cur*2,s,mid,val);
    int r=query(cur*2+1, mid+1, e, val-diff);
    return l+r;
}

int main() {
    init
    cin>>n;

    
    tree.resize(treeSize);
    
    // k번째 맛있는 사탕을 꺼내줌
    // -> multiSet 만드는 문제
    
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1){ // 사탕 꺼내기
            //사탕의 순위
            cin>>b;
            cout<<query(1,1,treeSize/2, b)<<"\n";
        }else{ // 사탕넣기
            // 사탕맛, 사탕개수
            // c가 양수 -> 넣기, 음수->빼기
            cin>>b>>c;
            update(startIdx+b-1,c);
        }
    }
    return 0;
}
