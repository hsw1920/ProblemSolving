//
//  main.cpp
//  1072
//
//  Created by 홍승완 on 2023/04/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long x,y;
long long z;
int main() {
    ios_base::sync_with_stdio(0);

    cin>>x>>y;
    z=y*100/x;
    
    int l=0;
    int r=1000000000;
    int m;
    
    if(z>=99){
        cout<<-1<<"\n";
        return 0;
    }
        
    
    while(l<=r){
        int m=(l+r)/2;
        int tmp=(y+m)*100/(x+m);
        if(z<tmp)r=m-1;
        else l=m+1;
    }
    
    // 게임횟수, 이긴게임
    // 소수점은 버림
    cout<<l<<"\n";
    
    return 0;
}

