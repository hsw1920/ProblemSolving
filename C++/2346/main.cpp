//
//  main.cpp
//  2346
//
//  Created by 홍승완 on 2023/04/20.
//

#include <iostream>
#include <deque>

using namespace std;

int n;
deque<pair<int,int>>dq;
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        dq.push_back({tmp,i+1});
    }
    while(dq.size()){
        int cur=dq.front().first;
        cout<<dq.front().second<<" ";
        dq.pop_front();
        if(dq.empty())break;
        if(cur>0){
            for(int i=0;i<cur-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for(int i=0;i<abs(cur);i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    
    return 0;
}
