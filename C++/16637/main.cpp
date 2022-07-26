//
//  main.cpp
//  16637
//
//  Created by 홍승완 on 2022/07/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;
string str;
int n;
vector<int>num;
vector<char>oper_str;
int res=-1e9;

int oper(char a, int b,int c){
    if(a=='+')return b+c;
    if(a=='-')return b-c;
    if(a=='*')return b*c;
    return 0;
}

void go(int idx, int _num){
    if(idx==num.size()-1){
        res=max(res,_num);
        return;
    }
    // 다음 계산결과를 넘김 (괄호x)
    go(idx+1,oper(oper_str[idx],_num,num[idx+1]));
    // 다음계산결과 (괄호o)
    if(idx+2<=num.size()-1){
        int tmp=oper(oper_str[idx+1],num[idx+1],num[idx+2]);
        go(idx+2,oper(oper_str[idx],_num,tmp));
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++){
        if(i%2==0)num.push_back(str[i]-'0');
        else oper_str.push_back(str[i]);
    }
    go(0,num[0]);
    cout<<res<<"\n";
    
    return 0;
}
