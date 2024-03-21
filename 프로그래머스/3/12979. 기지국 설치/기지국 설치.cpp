#include <bits/stdc++.h>

using namespace std;
// N 2억
// stations 1만, 오름차순, N보다 같거나 작은 자연수
// w 1만

// 기지국 교체 -> 모든 아파트에 전파하는 기지국 최소개수
// W는 양옆 기지국 전파범위
// 2만*1만 복잡도 가능
// n은 아파트 개수

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<pair<int,int>>v;
    // init 시작점 잡기.
    int ped=0;
    for(int i=0;i<stations.size();i++){
        int cst = stations[i]-w; // 3
        int ced = stations[i]+w; // 5

        if(ped+1<cst){
            v.push_back({ped+1,cst-1});
        } 
        
        ped = ced;
        
        if(i==stations.size()-1 && ced < n){
            v.push_back({ced+1,n});
        }
    }
    
    for(auto k: v){
        int len = k.second-k.first+1;
        int width = 2*w+1;
        answer += (len+width-1)/width;
    }
    

    return answer;
}