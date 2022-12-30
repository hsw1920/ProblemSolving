//
//  main.cpp
//  16507
//
//  Created by 홍승완 on 2022/12/27.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int maps[1001][1001];
    
    int r,c,q,k;
    cin>>r>>c>>q;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>maps[i][j];
        }
    }
    
    for(int i=1;i<=r;i++){
        for(int j=2;j<=c;j++){
            maps[i][j]+=maps[i][j-1];
        }
    }
    
    int r1,c1,r2,c2;
    int w,h;
    int res1,res2;
    
    for(int i=0;i<q;i++){
        res1=res2=0;
        cin>>r1>>c1>>r2>>c2;
        w=c2-c1+1;
        h=r2-r1+1;
        res1+=(w*h);
        
        int sum=0;
        for(int j=r1;j<=r2;j++){
            sum+=(maps[j][c2]-maps[j][c1-1]);
        }
        res2+=sum;
        
        cout<<res2/res1<<"\n";
    }
    
    

    return 0;
}
