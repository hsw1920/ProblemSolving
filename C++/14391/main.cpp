//
//  main.cpp
//  14391
//
//  Created by 홍승완 on 2022/08/24.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n,m;
int maps[5][5];
int sum=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            maps[i][j]=s[j]-'0';
        }
    }
    int ans=0;
    // 모든 칸에 대하여 가로로자를경우 0, 세로로자를경우 1으로 하면
    // 2^16의 경우로 브루트포스가 가능해진다. -> 비트마스킹 이용
    
    //0가로, 1세로의 모든경우 최대 2^(n*m)
    for(int b=0;b<(1<<(n*m));b++){
        int sum=0;
        
        //가로모양 자른것 계산
        for(int i=0;i<n;i++){
            int now=0;
            for(int j=0;j<m;j++){
                
                //정사각형 종이조각을 한줄로 이어붙일때 idx
                int k = i*m+j;
                
                //k번째 자리값이 0이면 가로
                if((b&(1<<k))==0){
                    now=now*10+maps[i][j];
                }
                //1이면 세로
                else {
                    sum+=now;
                    now=0;
                }
            }
            // 한 행 끝나면 sum에 더함
            sum+=now;
        }
        
        //세로모양자른경우 계산
        for(int j=0;j<m;j++){
            int now=0;
            for(int i=0;i<n;i++){
                //idx
                int k=i*m+j;
                //세로경우 숫자만들기
                if((b&(1<<k))!=0){
                    now=now*10+maps[i][j];
                }
                else{
                    sum+=now;
                    now=0;
                }
            }
            sum+=now;
        }
        
        // 최댓값 갱신
        ans=max(ans,sum);
        
    }
    cout<<ans<<"\n";
    
    
    return 0;
}
