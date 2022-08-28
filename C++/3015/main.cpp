//
//  main.cpp
//  3015
//
//  Created by 홍승완 on 2022/08/27.
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
    
    long long n, res,tmp;
    stack<pair<long long, long long>>st;
    cin>>n;
    res=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        int cnt=1;
        while(st.size()&& st.top().first<=tmp){
            res+=st.top().second;
            if(st.top().first==tmp){
                cnt=st.top().second +1;
            }
            else{
                cnt=1;
            }
            st.pop();
        }
        if(st.size()){
            res++;
        }
        st.push({tmp,cnt});
    }
    cout<<res<<"\n";
    
    return 0;
}
