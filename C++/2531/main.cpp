//
//  main.cpp
//  2531
//
//  Created by 홍승완 on 2023/06/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n,d,k,c; // 접시, 초밥가지, 연속먹는접시, 쿠폰번호
vector<int>v;
int chk[30001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>d>>k>>c;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp; // 초밥 종류
        v.push_back(tmp);
    }
    int flag=0;
    int cp=0;
    int res=0;
    for(int i=0;i<n;i++){
        flag=0;
        cp=1;
        for(int j=i;j<i+k;j++){
            if(chk[v[j%n]]==1)
               flag++;
            else
                chk[v[j%n]]=1;
            if(v[j%n]==c)
                cp=0;
        }
        res=max(res,k-flag+cp);
        memset(chk,0,sizeof(chk));
    }

    cout<<res<<"\n";
    return 0;
}
