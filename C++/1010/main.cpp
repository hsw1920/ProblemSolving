//
//  main.cpp
//  1010
//
//  Created by 홍승완 on 2023/06/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

int t,n,m;

int main() {
    init
    cin>>t;
    while(t--){
        cin>>n>>m;
        //mCn
        
        int dif=n;
        int tmp=1;
        long long set=1;
        for(int i=m;i>m-n;i--){
            set*=i;
            set/=tmp;
            tmp++;
        }
        
        cout<<set<<"\n";
    }
    return 0;
}
