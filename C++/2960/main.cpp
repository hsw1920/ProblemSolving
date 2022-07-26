//
//  main.cpp
//  2960
//
//  Created by 홍승완 on 2022/05/25.
//

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int cnt=0;
    int num[1001]={0,};
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(num[j]==0){
                cnt++;
                num[j]=1;
                if(cnt==k){
                    cout<<j;
                    return 0;
                }
            }
        }
        
    }
    return 0;
}
