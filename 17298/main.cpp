//
//  main.cpp
//  17298
//
//  Created by 홍승완 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n;
vector<int>v;
stack<int>st;
int res[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }
    for(int i=n-1;i>=0;i--){
        while(st.size()&&st.top()<=v[i]) st.pop();
        if(st.empty()) res[i]=-1;
        else res[i]=st.top();
        st.push(v[i]);
    }
    
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
   
    return 0;
}
