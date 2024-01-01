//
//  main.cpp
//  2143
//
//  Created by 홍승완 on 2023/06/03.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long T,n,m;
long long A[1001],B[1001];
long long psum1[1001],psum2[1001];
vector<long long>v1,v2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>T;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        psum1[i]=psum1[i-1]+A[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>B[i];
        psum2[i]=psum2[i-1]+B[i];
    }
    
    //A와 B의 부 배열의 합이 T가 되는 모든 쌍의 개수를 구해라
    // 각 부배열이 될 수 있는 집합을 모두 구한다?
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            v1.push_back(psum1[j]-psum1[i-1]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            v2.push_back(psum2[j]-psum2[i-1]);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    long long res=0;
    for(int i=0;i<v1.size();i++){
        long long subA=v1[i];
        long long target = T-subA;
        res += upper_bound(v2.begin(), v2.end(), target) - lower_bound(v2.begin(), v2.end(), target);
    }
    
    cout<<res<<"\n";
    
    return 0;
}
