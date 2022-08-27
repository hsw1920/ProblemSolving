//
//  main.cpp
//  15926
//
//  Created by 홍승완 on 2022/08/25.
//

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n;
string str;
stack<int> st;
int res,cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>str;
    st.push(-1);
    for(int i=0;i<n;i++){
        if(str[i]=='(')
            st.push(i);
        
        if(str[i]==')') {
            st.pop();
            if(st.size()){
                res = max(res, i-st.top());
            }
            else {
                st.push(i);
            }
        }
    }
    cout<<res<<"\n";
  
    return 0;
}
