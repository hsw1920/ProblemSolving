//
//  main.cpp
//  6603
//
//  Created by 홍승완 on 2023/01/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        vector<int>v,vis;
        int tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int i=0;i<6;i++)vis.push_back(0);
        for(int i=0;i<n-6;i++)vis.push_back(1);
        
        do{
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    cout<<v[i]<<" ";
                }
            }
            cout<<"\n";
        }while(next_permutation(vis.begin(), vis.end()));
        cout<<"\n";
    }

    return 0;
}
