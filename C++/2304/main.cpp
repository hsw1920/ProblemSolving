//
//  main.cpp
//  2304
//
//  Created by 홍승완 on 2022/10/16.
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

    int n,idx,k;
    vector<pair<int,int>>v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>idx>>k;
        v.push_back({idx,k});
    }
    sort(v.begin(),v.end());
    // top : (idx, h)
    // nextTop : (idx2: h2) -> 나오면? 스택에서 top미만은 다 뺌
    // nextTop이 top됨
    
    // first-> idx
    // second-> value
    int topIdx = v[n-1].first;
    int topValue = v[n-1].second;
    stack<pair<int,int>>st;
    st.push({topIdx,topValue});
    
    for(int i=n-2;i>=0;i--){
        if(v[i].second>topValue){
            while(st.top().second!=topValue){
                st.pop();
            }
            st.push({v[i].first,v[i].second});
            topIdx=v[i].first;
            topValue=v[i].second;
        }
        else if(v[i].second<topValue){
            if(v[i].second > st.top().second){
                while(v[i].second > st.top().second){
                    st.pop();
                }
            }
            st.push({v[i].first,v[i].second});
        }
        else {
            while(st.top().second!=topValue){
                st.pop();
            }
            st.push({v[i].first,v[i].second});
        }
    }
    
    int res=0;
    int curIdx, curValue, nxtIdx, nxtValue;
    curIdx = st.top().first;
    curValue = st.top().second;
    st.pop();
    while(st.size()){
        nxtIdx = st.top().first;
        nxtValue = st.top().second;
        
        if(curValue<nxtValue){
            res += (nxtIdx-curIdx)*curValue;
        }
        else {
            res += (nxtIdx-curIdx)*nxtValue;
        }
        curIdx = nxtIdx;
        curValue = nxtValue;
        st.pop();
    }
    res+=topValue;

    cout<<res<<"\n";
    
    
    return 0;
}
