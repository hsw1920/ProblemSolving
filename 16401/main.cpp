//
//  main.cpp
//  16401
//
//  Created by 홍승완 on 2022/05/15.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int m,n;
vector<int>snack;
long long sum=0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 과자길이는 최대 10억 조카 100만 과자 100만
    cin>>m>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        sum+=tmp;
        snack.push_back(tmp);
    }
    //못 나눠주면
    if(sum<m){
        cout<<0;
        return 0;
    }
    sort(snack.begin(),snack.end());
    int a=1,b=snack[n-1];
    int mid=(a+b)/2;
    // 과자길이의 mid 바운더리를 좁혀나가자 -> 이분탐색
    // 이때 조카수를 고려해야함
    int res=0;
    while(a<=b){
        int k=0,t=0;
        mid=(a+b)/2;
        int st=lower_bound(snack.begin(),snack.end(),mid)-snack.begin();
        for(int i=st;i<n;i++){
            k+=(snack[i]/mid);
            if(k>=m){
                t=1;
                res=mid;
                break;
            }
        }
        if(t!=1){
            b=mid-1;
        }
        else{
            a=mid+1;
        }
    }
    cout<<res;
    return 0;
}
