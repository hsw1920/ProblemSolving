//
//  main.cpp
//  9996
//
//  Created by 홍승완 on 2022/06/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin>>n;
    string s,tmp;
    cin>>s;
    // 입력받은 문자열 s를 * 기준으로 앞뒤 나누기
    // find로 *위치 찾고 앞부분 뒷부분 문자열 찾기
    string pre,suf;
    int idx= find(s.begin(),s.end(),'*')-s.begin();
    // int idx=s.find('*'); 위와 동일한 코드
    pre=s.substr(0,idx);
    suf=s.substr(idx+1,s.size());
    
    for(int i=0;i<n;i++){
        cin>>tmp;
        //사이즈 반례체크 !!!
        if(pre.size()+suf.size()>tmp.size()){
            cout<<"NE"<<"\n";
            continue;
        }
        if(pre==tmp.substr(0,idx) && suf==tmp.substr(tmp.size()-suf.size(),tmp.size())){
            cout<<"DA"<<"\n";
        }
        else cout<<"NE"<<"\n";
    }
    return 0;
}
