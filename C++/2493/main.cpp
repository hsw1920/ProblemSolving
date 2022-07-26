//
//  main.cpp
//  2493
//
//  Created by 홍승완 on 2022/03/25.
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int arr[500001]={0,};
    vector<int>st;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        st.push_back(k);
    }
    stack<pair<int,int>>s;
    s.push({st[n-1],n-1});
    for(int i=n-2;i>=0;i--){
        while(!s.empty()&&s.top().first<=st[i]){
            arr[s.top().second]=i+1;
            s.pop();
        }
        s.push({st[i],i});
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
