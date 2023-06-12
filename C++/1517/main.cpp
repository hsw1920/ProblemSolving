//
//  main.cpp
//  1517
//
//  Created by 홍승완 on 2023/06/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<long long>tree;
pair<long long,long long>arr[500005];
long long ans=0;

long long query(int s, int e){
    long long psum=0;
    while(s<=e){
        if(s%2==1)psum+=tree[s++];
        if(e%2==0)psum+=tree[e--];
        s/=2;
        e/=2;
    }
    return psum;
}

void update(int i){
    tree[i]=1;
    while(i){
        if(i%2==0){
            tree[i/2]=tree[i]+tree[i+1];
        }
        else{
            tree[i/2]=tree[i]+tree[i-1];
        }
        i/=2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr[i]={tmp,i};
    }
    sort(arr,arr+n);
    int h=ceil(log2(n));
    int treeSize=1<<(h+1);
    int startIdx=treeSize/2;
    tree.resize(treeSize+1);
    
    for(int i=0;i<n;i++){
        int targetIdx=arr[i].second; // 가장 작은 값의 인덱스
        // 그 트리에 그 값보다 작은 값이 오른쪽에 있는지여부 확인
        ans+=query(startIdx+targetIdx+1,startIdx+n-1);
        // 해당 값을 트리에 업데이트
        update(startIdx+targetIdx);
    }

    cout<<ans<<"\n";
    
    return 0;
}

