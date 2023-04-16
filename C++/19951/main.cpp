//
//  main.cpp
//  19951
//
//  Created by 홍승완 on 2023/04/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,h,a,b,k;
vector<int>v(100001,0);
vector<int>psum(100001,0);


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    // a~b까지 높이가 각각 k만큼 +-
    for(int i=0;i<m;i++){
        cin>>a>>b>>k;
        psum[a]+=k;
        psum[b+1]-=k;
    }
    for(int i=1;i<=n;i++){
        psum[i]+=psum[i-1];
        v[i]+=psum[i];
        cout<<v[i]<<" ";
    }
    return 0;
}
