//
//  main.cpp
//  2852
//
//  Created by 홍승완 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,num;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t[2881]={0,};
    int team1=0,team2=0;
    int t1=0,t2=0;
    int h,m;
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num>>str;
        h=(str[0]-'0')*10+(str[1]-'0');
        m=(str[3]-'0')*10+(str[4]-'0');
        if(num==1){
            t[60*h+m]=1;
        }
        else {
            t[60*h+m]=2;
        }
    }
    int times=0;
    while(times<2880){
        if(t[times]==1)team1++;
        if(t[times]==2)team2++;
        
        if(team1>team2) t1++;
        else if(team2>team1) t2++;
        times++;
    }
    int h1=t1/60,h2=t2/60,m1=t1%60,m2=t2%60;
    if(h1<10)cout<<0<<h1;
    else cout<<h1;
    cout<<":";
    if(m1<10)cout<<0<<m1;
    else cout<<m1;
    cout<<"\n";
    
    if(h2<10)cout<<0<<h2;
    else cout<<h2;
    cout<<":";
    if(m2<10)cout<<0<<m2;
    else cout<<m2;
    cout<<"\n";
//    cout<<t1/60<<":"<<t1%60<<"\n";
//    cout<<t2/60<<":"<<t2%60<<"\n";
    return 0;
}
