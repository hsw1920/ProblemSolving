#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<pair<int,int>>v;
    int ped=0;
    for(int i=0;i<stations.size();i++){
        int cst = stations[i]-w; 
        int ced = stations[i]+w; 

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