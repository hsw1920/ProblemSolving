//
//  main.cpp
//  1067-D
//
//  Created by 홍승완 on 2023/07/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <tuple>
#include <map>
#include <iomanip>
#include <numeric>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;
typedef tuple<int,int,int> iii;
typedef pair<ll, ll> pll;

int n,m,k;
char maps[501][501];
char maps2[501][501];
int main() {
    init;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
            maps2[i][j]=maps[i][j];
        }
    }
    
    int cnt[26];
    for(int K=0;K<k*k;K++){
        int x=K/k;
        int y=K%k;
        for(int i=0;i<26;i++)cnt[i]=0;
        for(int i=x;i<n;i+=k){
            for(int j=y;j<m;j+=k){
                int cur = maps[i][j]-'A';
                cnt[cur]++;
            }
        }
        int num=0;
        int idx=0;
        for(int i=0;i<26;i++){
            if(num<cnt[i]){
                idx=i;
                num=cnt[i];
            }
        }
//        cout<<idx<<" ";
        for(int i=x;i<n;i+=k){
            for(int j=y;j<m;j+=k){
                maps[i][j]='A'+idx;
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]!=maps2[i][j])res++;
        }
    }
    cout<<res<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<maps[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
