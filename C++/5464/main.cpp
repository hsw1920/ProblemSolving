//
//  main.cpp
//  5464
//
//  Created by 홍승완 on 2023/04/20.
//

#include <iostream>
#include <queue>

using namespace std;

int n,m,pay[101],weight[2001],order[4001],tmp,vis1[2001],vis2[2001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
queue<int>q;
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        //cin>>pay[i];
        cin>>tmp;
        pq.push({i,tmp});
    }
    for(int i=1;i<=m;i++){
        cin>>weight[i];
    }
    int res=0;
    for(int i=0;i<2*m;i++){
        cin>>tmp;
        int cur=abs(tmp);
        if(tmp>0){
            if(pq.size()){
                vis1[cur]=pq.top().first;
                vis2[cur]=pq.top().second;
                res+=weight[cur]*pq.top().second;
                pq.pop();
                
            }
            else{
                q.push(tmp);
            }
        }
        else{
            pq.push({vis1[cur],vis2[cur]});
            // 나올차량 있으면
            if(q.size()){
                int out=q.front(); // 나올 차량번호
                q.pop();
                vis1[out]=pq.top().first;
                vis2[out]=pq.top().second;
                res+=weight[out]*pq.top().second;
                pq.pop();
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}
