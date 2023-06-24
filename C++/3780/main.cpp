//
//  main.cpp
//  3780
//
//  Created by 홍승완 on 2023/06/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);
using namespace std;

int tc,n,a,b;
int set[20001];
int dist[20001];
char x;

int Find(int x){
    if(x==set[x])return x;
    int idx=Find(set[x]);
    dist[x]+=dist[set[x]];
    return set[x]=idx;
}

void Union(int a, int b){
    dist[a]=abs(a-b)%1000;
    set[a]=b;
}

int main() {
    init
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i=1;i<=n;i++){
            set[i]=i;
            dist[i]=0;
        }
        while(1){
            cin>>x;
            // 기업x와 현재 x의 센터까지 거리출력
            if(x=='E'){
                cin>>a;
                Find(a);
                cout<<dist[a]<<"\n";
            }
            // 센터 a를 기업b에 연결함
            else if(x=='I'){
                cin>>a>>b;
                Union(a,b);
            }
            else if(x=='O'){
                break;
            }
        }
    }
    return 0;
}
