//
//  main.cpp
//  1021
//
//  Created by 홍승완 on 2022/10/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // 1. 1원소 뽑기
    // 2. 왼쪽이동
    // 3. 오른쪽이동
    
    // 큐 크기 n, 뽑을개수 m
    // 뽑을 수를 순서대로 뽑기위한
    // 2,3번 연산의 최솟값을 구하기
    
    deque<int> dq;
    int n,m;
    vector<int>v;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        dq.push_back(i+1);
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    //  0 1 2 3 4 5 6 (7) 8 9 10 ...
    int ans = 0;
    for(int i=0;i<m;i++){
        //찾아야할거 v[i]
        int target = v[i];
        int idx = find(dq.begin(), dq.end(), v[i]) - dq.begin();
        // 찾은 idx가 왼,오 어느게 나은지
        int k = dq.size();
        k = min(abs(k-idx), idx);
        ans+=k;
        //cout<<"k: "<<k<<"\n";
        
        while(dq.front()!=target){
            int num = dq.back();
            dq.pop_back();
            dq.push_front(num);
        }
        dq.pop_front();
    }

    cout<<ans<<"\n";
    
    return 0;
}
