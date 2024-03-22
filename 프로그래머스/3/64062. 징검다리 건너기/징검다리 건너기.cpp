#include <bits/stdc++.h>

using namespace std;

bool binary_search(vector<int>stones, int k, int mid){
    int cnt=0;
    for(int i=0;i<stones.size();i++){
        if(stones[i]<mid){
            cnt++;
        }else{
            cnt=0;
        }
        // k번연속으로 작으면 못건넘
        if(cnt==k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int st = 1;
    int ed= *max_element(stones.begin(),stones.end());
    
    while(st<=ed){
        int mid = (st+ed)/2;
        if(binary_search(stones,k,mid)){
            st = mid +1;
            if(answer < mid) answer = mid;
        }
        else{
            ed = mid -1;
        }     
    }
    
    return answer;
}