//
//  main.cpp
//  9934
//
//  Created by 홍승완 on 2022/07/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int k;
int arr[1025];
vector<int> res[10];

void insertTree(int depth, int st, int ed){
    if(st>=ed)return;
    int mid = (st+ed)/2;
    res[depth].push_back(arr[mid]);
    insertTree(depth+1, st, mid);
    insertTree(depth+1, mid+1, ed);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;
    int n= pow(2, k)-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertTree(0,0,n);
    for(int i=0;i<k;i++){
        for(auto e:res[i]){
            cout<<e<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
