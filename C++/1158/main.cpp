//
//  main.cpp
//  1158
//
//  Created by 홍승완 on 2022/10/17.
//

#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    deque<int> dq;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        dq.push_back(i+1);
    cout<<"<";
    while(dq.size()){
        for(int i=0;i<k-1;i++){
            int tmp = dq.front();
            dq.push_back(tmp);
            dq.pop_front();
        }
        cout<<dq.front();
        dq.pop_front();
        
        if(dq.size())
            cout<<", ";
    }
    cout<<">";
    return 0;
}
