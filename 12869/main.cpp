//
//  main.cpp
//  12869
//
//  Created by 홍승완 on 2022/07/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n;
vector<int>idx;
int visited[3];
int stop=0;
int res=1e9;
void next(vector<int>idx, vector<int>scv, int cnt){
    if(idx.size()==1||idx.size()==3){
        for(int i=0;i<idx.size();i++){
            if(i==0)scv[idx[i]]-=9;
            else if(i==1)scv[idx[i]]-=3;
            else scv[idx[i]]-=1;
        }
    }
    else if(idx.size()==2){
        scv[idx[0]]-=10;
        scv[idx[1]]-=3;
    }
    
    if(idx.size()==1){
        if(scv[0]<=0){
            res=min(res,cnt);
            return;
        }
    }
    else if(idx.size()==2){
        if(scv[0]<=0&&scv[1]<=0){
            res=min(res,cnt);
            return;
        }
    }
    else{
        if(scv[0]<=0&&scv[1]<=0&&scv[2]<=0){
            res=min(res,cnt);
            return;
        }
    }
    
    cnt++;
    vector<int>a;
    for(int i=0;i<n;i++)
        a.push_back(i);
    
    do{
        next(a,scv,cnt);
    }while(next_permutation(a.begin(),a.end()));
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tmp;
    vector<int>scv;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        scv.push_back(tmp);
        idx.push_back(i);
    }
    do{
        next(idx,scv,1);
    }while(next_permutation(idx.begin(),idx.end()));
    cout<<res<<"\n";
    return 0;
}
