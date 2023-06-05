//
//  main.cpp
//  1477
//
//  Created by 홍승완 on 2023/06/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,l; // 휴게소, 현재 n개, m개 더 세움, 고속도로길이 l
vector<int>v;


// 휴게소를 m개 더지어서 없는구간의 길이의 최댓갓을 최소로 함
// 반드시 m개를 지어야함

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>l;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    v.push_back(0);
    v.push_back(l);
    
    sort(v.begin(),v.end());

    int low=1;
    int right=l;
    
    int res=0;
    while(low<=right){
        int mid=(low+right)/2;
        int cnt=0;
        for(int i=1;i<v.size();i++){
            int dist=v[i]-v[i-1];
            cnt+=dist/mid;
            if(dist%mid==0)
                cnt--;
        }
        if(cnt>m)
            low=mid+1;
        else {
            right=mid-1;
            res=mid;
        }
    }
    
    cout<<res<<"\n";


    
    return 0;
}
