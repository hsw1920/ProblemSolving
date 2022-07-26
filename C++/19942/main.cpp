//
//  main.cpp
//  19942
//
//  Created by 홍승완 on 2022/07/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

map<int, vector<vector<int>>> res_v;
int res=1e9;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,mp,mf,ms,mv; // 단지탄비
    int b,c,d,e,sum=0;
    int p[16],f[16],s[16],vi[16],cost[16];
    cin>>n;
    cin>>mp>>mf>>ms>>mv;
    for(int i=0;i<n;i++){
        cin>>p[i]>>f[i]>>s[i]>>vi[i]>>cost[i];
    }
    
    for(int i=1;i<(1<<n);i++){
        b=c=d=e=sum=0;
        vector<int>v;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){ //j번째 비트가 있을때
                v.push_back(j+1);
                b+=p[j];
                c+=f[j];
                d+=s[j];
                e+=vi[j];
                sum+=cost[j];
            }
        }
        if(b>=mp&&c>=mf&&d>=ms&&e>=mv){
            if(res>=sum){
                res=sum;
                res_v[res].push_back(v);
            }
        }
    }
    if(res==1e9)cout<<-1<<"\n";
    else {
        sort(res_v[res].begin(),res_v[res].end());
        cout<<res<<"\n";
        for(auto i: res_v[res][0]){
            cout<<i<<" ";
        }
    }
    
    return 0;
}
