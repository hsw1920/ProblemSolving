//
//  main.cpp
//  4375
//
//  Created by 홍승완 on 2022/06/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(scanf("%d",&n)!=EOF){
        int cnt=1,ret=1;
        while(1){
            if(cnt%n==0){
                printf("%d\n",ret);
                break;
            }
            else{
                cnt=(cnt*10)+1;
                cnt%=n;
                ret++;
            }
        }
    }
    return 0;
}
