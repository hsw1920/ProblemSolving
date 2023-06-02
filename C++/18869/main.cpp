//
//  main.cpp
//  18869
//
//  Created by 홍승완 on 2023/06/02.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int>v1[101];
vector<int>v2[101];
vector<int>v3[101];
// 균등한 우주의 쌍은 몇개?



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            cin>>tmp;
            v1[i].push_back(tmp);
            v2[i].push_back(tmp);
        }
        sort(v2[i].begin(),v2[i].end());
        v2[i].erase(unique(v2[i].begin(),v2[i].end()),v2[i].end());
        for(int j=0;j<n;j++){
            v3[i].push_back(lower_bound(v2[i].begin(), v2[i].end(), v1[i][j])-v2[i].begin());
        }
    }
    int res=0;
    for(int i=1;i<=m-1;i++){
        for(int j=i+1;j<=m;j++){
            if(v3[i]==v3[j])res++;
        }
    }
    cout<<res<<"\n";
    
    return 0;
}
