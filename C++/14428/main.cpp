//
//  main.cpp
//  14428
//
//  Created by 홍승완 on 2023/06/15.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n,m,a,b,c;
vector<int>tree;
int arr[100001];

int minIndex(int x, int y) // 더 작은 값의 인덱스를 반환하는 함수
{
    // 유효하지 않은 경우
    if (x == -1) return y;
    if (y == -1) return x;
    // 같은 경우 더 작은 인덱스 리턴
    if (arr[x] == arr[y]) return x < y ? x : y;
    else return arr[x] <= arr[y] ? x : y;
}

void init(int cur, int s, int e){
    if(s==e){
        tree[cur]=s;
        return ;
    }
    int mid=(s+e)/2;
    init(cur*2, s, mid);
    init(cur*2+1, mid+1, e);
    
    tree[cur]=minIndex(tree[cur*2], tree[cur*2+1]);
}

void update(int cur, int s, int e, int idx, int val){
    if(idx<s||idx>e)return;
    if(s==e){
        arr[idx]=val;
        tree[cur]=idx;
        return ;
    }
    int mid=(s+e)/2;
    update(cur*2,s,mid,idx,val);
    update(cur*2+1,mid+1,e,idx,val);
    
    tree[cur]=minIndex(tree[cur*2], tree[cur*2+1]);
}

int query(int cur, int s, int e, int qs, int qe){
    if(s>qe||e<qs) return -1;
    if(s>=qs&&e<=qe) return tree[cur];
    
    int mid = (s+e)/2;
    int left=query(cur*2, s, mid, qs, qe);
    int right=query(cur*2+1, mid+1, e, qs, qe);
    
    return minIndex(left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    fill(arr,arr+n-1,1e9);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int h=ceil(log2(n));
    int treeSize=1<<(1+h);
    tree.resize(treeSize+1);
    fill(tree.begin(),tree.end(),1e9);
    
    
    init(1,1,n);
    
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(a==1){
            update(1,1,n,b,c);
        }
        
        else if(a==2){
            cout<<query(1,1,n,b,c)<<"\n";
        }
    }
    
    return 0;
}
