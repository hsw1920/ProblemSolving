//
//  main.cpp
//  11003
//
//  Created by 홍승완 on 2022/03/29.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pint pair<int,int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,L;
    cin>>N>>L;
    int num;
    //우선순위큐??
    // N까진 pop없이 front가 최소
    // N이후부터는 pop push 하면서 최솟값 고르기 ??
    // 우선순위큐에 숫자와 limit경계를 같이 넣어주기
    // limit를 넘어서면 pop해야함
    priority_queue<pint,vector<pint>,greater<pint>>q;

    for(int i=0;i<L;i++){
        cin>>num;
        // i+L-1이 현재 인덱스보다 작으면 버려야함
        q.push({num,i+L-1});
        cout<<q.top().first<<" ";
    }
    for(int i=L;i<N;i++){
        cin>>num;
        q.push({num,i+L-1});
        while(q.top().second<i)
            q.pop();
        q.push({num,i+L-1});
        cout<<q.top().first<<" ";
    }
    return 0;
}
