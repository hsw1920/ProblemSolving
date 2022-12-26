//
//  main.cpp
//  11441
//
//  Created by 홍승완 on 2022/12/26.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m,s,e;
    int psum[100001];
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        psum[i]=tmp;
    }
    for(int i=2;i<=n;i++){
        psum[i]+=psum[i-1];
    }
    
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s>>e;
        cout<<psum[e]-psum[s-1]<<"\n";
    }

    return 0;
}
