//
//  main.cpp
//  20438
//
//  Created by 홍승완 on 2022/12/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,k,q,m,s,e;
    int stu[50001],sleep[50001];
    
    cin>>n>>k>>q>>m;
    for(int i=3;i<=n+2;i++)
        stu[i]=1;
    
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        sleep[tmp]=1;
    }
    
    for(int i=0;i<q;i++){
        int tmp;
        cin>>tmp;
        if(sleep[tmp]==1)continue;
        int next=tmp;
        while(next<=n+2){
            if(sleep[next]==1){
                next+=tmp;
                continue;
            }
            stu[next]=0;
            next+=tmp;
        }
    }
    
    
    for(int i=4;i<=n+2;i++){
        stu[i]+=stu[i-1];
    }
    
    for(int i=0;i<m;i++){
        cin>>s>>e;
        cout<<stu[e]-stu[s-1]<<"\n";
    }
 


    

    
    return 0;
}
