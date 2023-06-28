//
//  main.cpp
//  10164
//
//  Created by 홍승완 on 2023/06/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k;
int dp[226]={0,};
//행렬수 n*m, k는 O표시된 칸
//O 표시는 최대 1칸 -> 없을수도있음
//로봇은 오른쪽,아래만 이동가능
//O표시가 있으면 반드시 지나가야함

int main() {
    cin>>n>>m>>k;
    dp[1]=1;
    if(k==0){
        for(int i=2;i<=n*m;i++){
            // 첫열이 아닐때
            if(i%m!=1){
                // 첫 행이 아닐 때
                if(i>m&&(i-1)%m!=0){
                    dp[i]=dp[i-1]+dp[i-m];
                }
                // 첫행일때
                else{
                    dp[i]=1;
                }
            }
            // 첫열일때
            else{
                dp[i]=1;
            }
        }
        cout<<dp[n*m]<<"\n";
    }else{
        for(int i=2;i<=k;i++){
            // 첫열이 아닐때
            if(i%m!=1){
                // 첫 행이 아닐 때
                if(i>m&&(i-1)%m!=0){
                    dp[i]=dp[i-1]+dp[i-m];
                }
                // 첫행일때
                else{
                    dp[i]=1;
                }
            }
            // 첫열일때
            else{
                dp[i]=1;
            }
        }
        int tmp=dp[k];
        fill(dp,dp+n*m+1,0);
        dp[k]=tmp;
        
        for(int i=k+1;i<=n*m;i++){
            if((i-1)%m<(k-1)%m)dp[i]=0;
            // 첫열일때
            else if((k-1)%m==0 && (i-1)%m==0){
                dp[i]=dp[i-m];
            }
            // 첫행일때
            else if((i-1)/m==0){
                dp[i]=dp[i-1];
            }
            else{
                dp[i]=dp[i-1]+dp[i-m];
            }
        }
        cout<<dp[n*m]<<"\n";
    }

    return 0;
}

