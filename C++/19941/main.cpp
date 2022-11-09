//
//  main.cpp
//  19941
//
//  Created by 홍승완 on 2022/11/09.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int res=0;
    for(int i=0;i<n;i++){
        if(s[i]=='P'){
            for(int j=i-k;j<=i+k;j++){
                if(j<0)continue;
                else if(j>=n)break;
                if(s[j]=='H'){
                    res++;
                    s[j]='Z';
                    break;
                }
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}

