//
//  main.cpp
//  2910
//
//  Created by 홍승완 on 2024/01/11.
//

#include <bits/stdc++.h>
using namespace std;
int n,c,x;
typedef struct{
    int cnt,idx,elem;
}num;
unordered_map<int,int>arr,cnt;
vector<num>v;
vector<int>tmp;
bool compare(num a, num b){
    if(a.cnt==b.cnt){
        return a.idx<b.idx;
    }
    return a.cnt>b.cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>c;
    
    for(int i=1;i<=n;i++){
        cin>>x;
        
        if(cnt[x]==0)
            tmp.push_back(x);
        
        cnt[x]++;
        if(arr[x]==0)arr[x]=i;
        else arr[x]=min(arr[x],i);
        
    }
    
    for(int i=0;i<tmp.size();i++){
        int cur = tmp[i];
        if(cnt[cur]==0)continue;
        num curNum{cnt[cur],arr[cur],cur};
        v.push_back(curNum);
    }
    
    sort(v.begin(),v.end(),compare);
    
    for(auto k:v){
        for(int i=0;i<k.cnt;i++)
            cout<<k.elem<<" ";
    }
    
    return 0;
}
