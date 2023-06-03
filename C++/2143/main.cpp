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

int t,n,m;
vector<int>asum,bsum;
int a[1001];
int b[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>t;
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        int sum=a[i];
        asum.push_back(sum);
        for(int j=i+1;j<n;j++){
            sum+=a[j];
            asum.push_back(sum);
        }
    }
    for(int i=0;i<m;i++){
        int sum=b[i];
        bsum.push_back(sum);
        for(int j=i+1;j<m;j++){
            sum+=b[j];
            bsum.push_back(sum);
        }
    }
    sort(bsum.begin(),bsum.end());
    long long res=0;
    for(int i=0;i<asum.size();i++){
        int target=t-asum[i];
        int lb=lower_bound(bsum.begin(), bsum.end(), target)-bsum.begin();
        int ub=upper_bound(bsum.begin(), bsum.end(), target)-bsum.begin();
        res+=(ub-lb);
    }
    cout<<res<<"\n";
    
    return 0;
}
