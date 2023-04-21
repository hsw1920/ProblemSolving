//
//  main.cpp
//  17371
//
//  Created by 홍승완 on 2023/04/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,x,y;
vector<pair<int,int>>H;
int dist[1001];

double between(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}
// n개의 편의시설 존재함
// x,y좌표가 정수인곳에 편의시설 존재
// n개의 편의시설로 이동하는 거리의 평균이 최소가 되는 곳으로 이사가고 싶어함
// 가장 가까운 ~ 먼 편의 시설까지의 거리의 평균의 최소가 되는 곳으로 이동

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        H.push_back({x,y});
    }
    double mindist=1e9;
    int idx=0;
    for(int i=0;i<n;i++){
        double maxdist=-1e9;
        for(int j=0;j<n;j++){
            double target = between(H[i].first, H[i].second, H[j].first, H[j].second);
            if(maxdist<target){
                maxdist=target;
            }
        }
        if(mindist>maxdist){
            mindist=maxdist;
            idx=i;
        }
    }
    cout<<H[idx].first<<" "<<H[idx].second;
    return 0;
}
