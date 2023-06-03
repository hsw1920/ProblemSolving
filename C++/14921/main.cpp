//
//  main.cpp
//  14921
//
//  Created by 홍승완 on 2023/06/03.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int>v;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int i=0;
    int j=n-1;
    int res=1e9;
    while(i<j){
        int sum=v[i]+v[j];
        if(abs(sum)<abs(res))
            res=sum;
        if(sum==0)break;
        else if(sum<0){
            i++;
        }
        else {
            j--;
        }
    }
    
    cout<<res<<"\n";
    
    return 0;
}
