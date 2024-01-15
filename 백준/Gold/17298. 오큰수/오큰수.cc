//
//  main.cpp
//  17298
//
//  Created by 홍승완 on 2024/01/14.
//

#include <bits/stdc++.h>
using namespace std;
int n,num,dp[1000001],res[1000001];
vector<int>v;
stack<int>st,stk;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    // 수열 3 5 2 7
    // 오큰수 -> num보다 오른쪽에 있으면서 큰 수중에 가장 왼쪽에 있는 수
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    for(int i=n-1;i>=0;i--){
        while(st.size()&&st.top()<=v[i])
            st.pop();
        
        if(st.size()==0)res[i]=-1;
        else res[i]=st.top();
        
        st.push(v[i]);
    }
    for(int i=0;i<n;i++)cout<<res[i]<<" ";
    
    return 0;
}

