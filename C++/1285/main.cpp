//
//  main.cpp
//  1285
//
//  Created by 홍승완 on 2022/07/25.
//

//
//  main.cpp
//  19942
//
//  Created by 홍승완 on 2022/07/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;
int n;
int a[41], ret = 1e9;
string s;

void go(int here){
    if(here == n+1){
        int sum = 0;
        for(int i=1; i<= (1<<(n-1)); i*=2){ // 열 확인 00001 00010 00100 01000 10000...
            int cnt=0;
            for(int j=1; j<=n;j++){
                if(a[j]&i) // 열과 겹치면 cnt++ (==해당 열이 H라면 cnt++)
                    cnt++;
            }
            sum+=min(cnt,n-cnt); //
        }
        ret = min(ret, sum);
        return;
    }
    a[here] = ~a[here];
    go(here+1);
    a[here] = ~a[here];
    go(here+1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int value = 1;
        for(int j=0;j<n;j++){
            if(s[j]=='H'){ //위
                a[i] |= value; // 01 |= 10 -> 11
            }
            value *=2;
        }
    }
    go(1);
    cout<<ret<<"\n";
    return 0;
}
