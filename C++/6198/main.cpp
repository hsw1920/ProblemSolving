//
//  main.cpp
//  6198
//
//  Created by 홍승완 on 2022/03/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n;
    cin>>n;
    stack<int> st;
    long long int res=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        while(!st.empty()&&st.top()<=tmp){
            st.pop();
        }
        st.push(tmp);
        res+=st.size()-1;
    }
    cout<<res;
    return 0;
}
