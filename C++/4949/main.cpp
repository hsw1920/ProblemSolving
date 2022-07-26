//
//  main.cpp
//  4949
//
//  Created by 홍승완 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(1){
        getline(cin,str);
        if(str==".")break;
        stack<char>st;
        for(int i=0;i<str.length();i++){
            if(st.size()){
                if(st.top()=='['&&str[i]==']') st.pop();
                else if(st.top()=='('&&str[i]==')') st.pop();
                else if(str[i]=='('||str[i]==')'||str[i]=='['||str[i]==']') st.push(str[i]);
            }
            else if(str[i]=='('||str[i]==')'||str[i]=='['||str[i]==']') st.push(str[i]);
        }
        if(st.size())cout<<"no\n";
        else cout<<"yes\n";
    }
    
    return 0;
}
