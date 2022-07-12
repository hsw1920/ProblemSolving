//
//  main.cpp
//  9012
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
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        stack<char>st;
        cin>>str;
        for(int i=0;i<str.length();i++){
            if(st.size()&&st.top()=='('&&str[i]==')'){
                st.pop();
            }
            else {
                st.push(str[i]);
            }
        }
        if(st.size())cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
