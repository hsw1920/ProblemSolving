//
//  main.cpp
//  1654
//
//  Created by 홍승완 on 2023/04/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k,n;
vector<long long>set;
// n개의 랜선 만들어야함
// k개의 랜선 갖고있음. 길이가 제각각
// k개의 랜선을 각각 잘라서 만들어야함 -> 같은길이로
// 300 -> 140x2 ->20버려야함


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>k>>n;
    for(int i=0;i<k;i++){
        long long tmp;
        cin>>tmp;
        set.push_back(tmp);
    }
    sort(set.begin(),set.end());
    long long l=1;
    long long r=set[k-1];
    long long res=0;
    while(l<=r){
        long long mid=(l+r)/2;
        long long tmp=0;
        for(int i=0;i<k;i++){
            tmp+=(set[i]/mid);
        }
        if(tmp>=n){
            res=max(res,mid);
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    cout<<res<<"\n";
    
    return 0;
}
