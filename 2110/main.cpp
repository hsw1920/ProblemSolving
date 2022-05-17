//
//  main.cpp
//  2110
//
//  Created by 홍승완 on 2022/05/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,c;
vector<int>v;

bool possible(int dist){
    int cnt=1;
    int prev=v[0];
    for(int i=1;i<n;i++){
        if(v[i]-prev>=dist){
            cnt++;
            prev=v[i];
        }
    }
    if(cnt>=c)
        return true;
    else
        return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
    //c는 공유기 개수
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    
    // 가능한 공유기간 거리를 이분탐색을 통해 찾는다.
    
    int res=-1;
    int l=1,r=v.back()-v.front();
    while(l<=r){
        int mid=(l+r)/2;
        if(possible(mid)){
            res=max(res,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<res;
    return 0;
}
