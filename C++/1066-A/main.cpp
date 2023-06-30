//
//  main.cpp
//  1066-A
//
//  Created by 홍승완 on 2023/06/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
int res[21];
int ans=0;
vector<int>mk;

void pulling(vector<int>v, int idx, int cnt);
void pushing(vector<int>v, int idx, int cnt);

void pushing(vector<int>v, int idx, int cnt){
    
    if(cnt==k){
        int num=0;
        for(int i=0;i<n;i++){
            if(v[i]==res[i]){
                num++;
            }
        }
        ans=max(ans,num);
        return ;
    }
    
    for(int i=n-1;i>idx;i--){
        swap(v[i],v[i-1]);
    }
    v[idx]=0;
    int num=0;
    for(int i=0;i<n;i++){
        if(v[i]==res[i]){
            num++;
        }
    }
    ans=max(ans,num);
    
    for(int i=0;i<n;i++){
        pushing(v, i, cnt+1);
        pulling(v, i, cnt+1);
    }
    
}

void pulling(vector<int>v, int idx, int cnt){
    if(cnt==k){
        int num=0;
        for(int i=0;i<n;i++){
            if(v[i]==res[i]){
                num++;
            }
        }
        ans=max(ans,num);
        return ;
    }
    for(int i=idx;i<n-1;i++){
        swap(v[i],v[i+1]);
    }
    v[n-1]=0;
    int num=0;
    for(int i=0;i<n;i++){
        if(v[i]==res[i]){
            num++;
        }
    }
    ans=max(ans,num);
    for(int i=0;i<n;i++){
        pushing(v, i, cnt+1);
        pulling(v, i, cnt+1);
    }
}


int main() {
    cin>>n>>k;
    mk.resize(n);
    for(int i=0;i<n;i++){
        cin>>res[i];
    }
    for(int i=0;i<n;i++){
        cin>>mk[i];
    }
    
    int num=0;
    for(int i=0;i<n;i++){
        if(mk[i]==res[i]){
            num++;
        }
    }
    ans=max(ans,num);
    
    for(int i=0;i<n;i++){
        pushing(mk, i, 0);
        pulling(mk, i, 0);
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
