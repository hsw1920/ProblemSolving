//
//  main.cpp
//  9252
//
//  Created by 홍승완 on 2022/03/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string str1,str2;
    cin>>str1>>str2;
    int dp[1001][1001]={0,};
    int a=str1.size(), b=str2.size();
    for(int i=1;i<=b;i++){
        for(int j=1;j<=a;j++){
            if(str1[j-1]==str2[i-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int k=str1.size();
    string res="";
    for(int i=b;i>0;i--){
        if (dp[i][k] == 0)
            break;
        for(int j=k;j>0;j--){
            if (dp[i][j] == dp[i - 1][j])
                break;
            if(dp[i][j]!=dp[i][j-1]){
                res+=str1[j-1];
                k=j-1;
                break;
            }
        }
    }
    cout<<dp[str2.size()][str1.size()]<<"\n";
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i];
    }
    cout<<"\n";
    return 0;
}
