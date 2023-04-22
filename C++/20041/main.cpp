//
//  main.cpp
//  20041
//
//  Created by 홍승완 on 2023/04/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 도둑 반드시 움직임, 경찰 머무르기 가능
// 도둑 영원히 도망가능? -> 탈출 가능 : 불가능

typedef long long ll;
int n;
vector<pair<int,int>>p;
ll px,py;
ll sx,sy;
ll cnt[4];//상하좌우
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>px>>py;
        p.push_back({px,py});
    }
    cin>>sx>>sy;
    for(int i=0;i<n;i++){
        ll dx=p[i].first-sx;
        ll dy=p[i].second-sy;
        if(dx>=0&&dy>=0){
            if(dx>=dy)cnt[3]=1;
            if(dx<=dy)cnt[0]=1;
        }
        if(dx>=0&&dy<=0){
            if(dx>=abs(dy))cnt[3]=1;
            if(dx<=abs(dy))cnt[1]=1;
        }
        if(dx<=0&&dy>=0){
            if(abs(dx)>=dy)cnt[2]=1;
            if(abs(dx)<=dy)cnt[0]=1;
        }
        if(dx<=0&&dy<=0){
            if(abs(dx)>=abs(dy))cnt[2]=1;
            if(abs(dx)<=abs(dy))cnt[1]=1;
        }
    }
    int res=0;
    for(int i=0;i<4;i++){
        if(cnt[i])res++;
    }
    cout<< (res == 4 ? "NO":"YES");
    
    return 0;
}
