//
//  main.cpp
//  2805
//
//  Created by 홍승완 on 2023/04/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n,m;
vector<long long>tree;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    // 나무수n, 가져가려는 길이 m
    // 나무의 높이는 m보다 크거나 같음
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        tree.push_back(tmp);
    }
    sort(tree.begin(),tree.end());
    long long l=1;
    long long r=tree[n-1];
    long long res=0;
    while(l<=r){
        long long mid=(l+r)/2;
        long long target=0;
        for(auto k: tree){
            if(mid<k){
                target+=(k-mid);
            }
        }
        if(target>=m){
            l=mid+1;
            res=max(res,mid);
        } else{
            r=mid-1;
        }
    }
    cout<<res<<"\n";
    return 0;
}
