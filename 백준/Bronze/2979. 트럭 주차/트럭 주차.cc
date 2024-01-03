//
//  main.cpp
//  2979
//
//  Created by 홍승완 on 2024/01/03.
//

#include <bits/stdc++.h>

using namespace std;

int A,B,C,st,ed,res=0;
int cars[101];

int pay(int cnt){
    if(cnt==1) return A;
    else if(cnt==2) return B*2;
    else if(cnt==3) return C*3;
    else return 0;
}

int main() {
    cin>>A>>B>>C;
    
    for(int i=0;i<3;i++){
        cin>>st>>ed;
        for(int j=st;j<ed;j++)
            cars[j]++;
    }
    
    for(int i=0;i<=100;i++){
        res+=pay(cars[i]);
    }

    cout<<res<<"\n";
    return 0;
}
