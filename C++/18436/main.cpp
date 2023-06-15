//
//  main.cpp
//  18436
//
//  Created by 홍승완 on 2023/06/15.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,a,b,c;
int arr[100001];
vector<int>tree;

void init(int cur, int s, int e){
    if(s==e){
        // 짝수를 1이라고 저장
        if(arr[s]%2==0)
            tree[cur]=1;
    }
    else{
        int mid = (s+e)/2;
        init(cur*2,s,mid);
        init(cur*2+1,mid+1,e);
        tree[cur]=tree[cur*2]+tree[cur*2+1];
    }
}

void update(int cur, int s, int e, int idx, int val){
    if(idx<s||idx>e) return;
    if(s==e){
        if(val%2==0){
            arr[idx]=1;
            tree[cur]=1;
        }else{
            arr[idx]=0;
            tree[cur]=0;
        }
        return;
    }
    int mid=(s+e)/2;
    update(cur*2, s, mid, idx, val);
    update(cur*2+1, mid+1, e, idx, val);
    tree[cur]=tree[cur*2]+tree[cur*2+1];
}

int query(int cur, int s, int e, int qs, int qe){
    if(e<qs||s>qe)return 0;
    if(qs<=s&&e<=qe) return tree[cur];
    int mid=(s+e)/2;
    int left=query(cur*2, s, mid, qs, qe);
    int right=query(cur*2+1, mid+1, e, qs, qe);
    return left+right;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int h=ceil(log2(n));
    int treeSize=1<<(1+h);
    tree.resize(treeSize);
    init(1,0,n-1);
    
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(a==1){
            update(1,0,n-1,b-1,c);
        }
        // 짝수쿼리
        else if(a==2){
            cout<<query(1,0,n-1,b-1,c-1)<<"\n";
        }
        // 홀수쿼리
        else if(a==3){
            cout<<((c-1)-(b-1)+1)-query(1, 0, n-1, b-1, c-1)<<"\n";
        }
    }
    return 0;
}
