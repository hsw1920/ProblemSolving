//
//  main.cpp
//  1715
//
//  Created by 홍승완 on 2023/06/17.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int>v;
priority_queue<int,vector<int>,greater<int>>pq;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        pq.push(tmp);
    }
    int res=0;
    while(pq.size()>1){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        int sum=x+y;
        res+=sum;
        pq.push(sum);
    }
    cout<<res<<"\n";
    
    
    
    return 0;
}
