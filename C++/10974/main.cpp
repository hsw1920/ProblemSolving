//
//  main.cpp
//  10974
//
//  Created by 홍승완 on 2023/01/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;

    vector<int>v,vis;
    
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    
    do{
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }while(next_permutation(v.begin(), v.end()));
    cout<<"\n";
    
    return 0;
}
