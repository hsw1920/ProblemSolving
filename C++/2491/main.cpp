//
//  main.cpp
//  2491
//
//  Created by 홍승완 on 2023/07/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>v;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int res=1;
    int prev=v[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(v[i]>=prev){
            cnt++;
            res=max(res,cnt);
        }else{
            cnt=1;
        }
        prev=v[i];
    }
    prev=v[n-1];
    cnt=1;
    for(int i=n-2;i>=0;i--){
        if(v[i]>=prev){
            cnt++;
            res=max(res,cnt);
        }else{
            cnt=1;
        }
        prev=v[i];
    }
    cout<<res<<"\n";
    return 0;
}
