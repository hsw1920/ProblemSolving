//
//  main.cpp
//  5397
//
//  Created by 홍승완 on 2023/04/20.
//

#include <iostream>
#include <stack>

using namespace std;

int n;

int main() {
    cin>>n;
    while(n--){
        string s;
        stack<char>st1,st2,op;
        cin>>s;
        for(int i=0;i<s.size();i++){
            char cur=s[i];
            if(cur=='>'){
                if(st2.size()){
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else if(cur=='<'){
                if(st1.size()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            else if(cur=='-'){
                if(st1.size())st1.pop();
            }
            else {
                st1.push(cur);
            }
        }
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        while(st2.size()){
            cout<<st2.top();
            st2.pop();
        }
        cout<<"\n";
    }
    
    return 0;
}
