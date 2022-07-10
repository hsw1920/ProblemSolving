//
//  main.cpp
//  2979
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
using namespace std;

int main() {
    // 주차요금 1,2,3
    // 3개 줄에 각 트럭의 도착시간과 떠난시간
    int pay[4]={0,};
    for(int i=1;i<=3;i++)
        cin>>pay[i];
    int time[3][101]={0,};
    int s,e;
    for(int i=0;i<3;i++){
        cin>>s>>e;
        for(int j=s;j<e;j++){
            time[i][j]=1;
        }
    }
    int sum=0;
    int cnt;
    for(int i=1;i<=100;i++){
        cnt=0;
        for(int j=0;j<3;j++){
            if(time[j][i]==1)
                cnt++;
        }
        // 한 대당 pay[cnt]만큼 요금을 내야하니까 cnt를 곱해줘야함
        sum+=(pay[cnt]*cnt);
    }
    cout<<sum<<"\n";
    return 0;
}
