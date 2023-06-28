//
//  main.cpp
//  1495
//
//  Created by 홍승완 on 2023/06/28.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,s,m;
    int arr[51];
    int dp[51][1001];
    cin>>n>>s>>m;
    // v, v[i] -> i번째 곡을 연주하기 전 바꿀 수 있는 볼륨
    // 현재 볼륨p -> i번째 연주전 -> i번곡은 p+v[i]또는 p-v[i]로 연주해야함
    // 하지만 볼륨의 범위는 0~m 사이를 지켜야함
    // 모든 곡은 순서대로 연주함, 리스트에 적힌 차이로만 볼륨을 바꿀 수 있음
    // s는 시작볼륨
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    fill(&dp[0][0],&dp[50][1000],-1);
    dp[0][s]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(dp[i-1][j]==1){
                if(j+arr[i]<=m){
                    dp[i][j+arr[i]]=1;
                }
                if(j-arr[i]>=0){
                    dp[i][j-arr[i]]=1;
                }
            }
        }
    }
    int res=-1;
    for(int i=0;i<=m;i++){
        if(dp[n][i]==1){
            res=i;
        }
    }
    cout<<res<<"\n";
    
    return 0;
}
