//
//  main.cpp
//  3986
//
//  Created by 홍승완 on 2022/06/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt=0;
    cin>>n;
    string s;
    
    vector<string>v;
    for(int i=0;i<n;i++){
        cin>>s;
        stack<char>stk;
        for(int i=0;i<s.size();i++){
            if(!stk.empty()){
                if(s[i]==stk.top()){
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
            else stk.push(s[i]);
        }
        if(stk.empty()){
            cnt++;
        }
        
    }
    cout<<cnt<<"\n";
    
    return 0;
}
