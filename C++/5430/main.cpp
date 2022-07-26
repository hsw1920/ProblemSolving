//
//  main.cpp
//  5430
//
//  Created by 홍승완 on 2022/03/28.
//

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
int T,n;

int R(deque<int> dq){
    deque<int> q=dq;
    dq.clear();
    long long k=dq.size();
    while(k--){
        int w=q.back();
        q.pop_back();
        dq.push_back(w);
    }
    return 0;
}

int D(deque<int> dq){
    if(dq.size()>0){
        dq.pop_front();
    }
    else{
        return -1;
    }
    return 0;
}

int main() {
    //R 뒤집기 D 첫번째 수 버리기
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i=0;i<T;i++){
        int k;
        string f,num;
        cin>>f;
        cin>>k;
        cin>>num;
        deque<int>dq;
        int sum=0;
        for(int i=0;i<num.size();i++){
            if(num[i]==','||num[i]==']'){
                if(sum!=0)
                    dq.push_back(sum);
                sum=0;
                if(num[i]==']')
                    break;
            }
            else if(num[i]=='[')
                continue;
            else {
                sum=sum*10 +(num[i]-'0');
            }
        }
 
        int flag=0;
        bool r=false;
        for(int i=0;i<f.size();i++){
            if(f[i]=='R'&&!r){
                r=true;
            }
            else if(f[i]=='R'&&r){
                r=false;
            }
            else if(f[i]=='D'){
                if(dq.size()>0&&!r){
                    dq.pop_front();
                }
                else if(dq.size()>0&&r){
                    dq.pop_back();
                }
                else{
                    flag=-1;
                    cout<<"error\n";
                    break;
                }
            }
        }
        if(r){
            deque<int> q;
            long long k=dq.size();
            while(k--){
                int w=dq.back();
                dq.pop_back();
                q.push_back(w);
            }
            dq=q;
        }
        
        if(flag==0){
            long long k=dq.size();
            cout<<"[";
            for(int i=0;i<2*k-1;i++){
                if(i%2==0){
                    cout<<dq.front();
                    dq.pop_front();
                }
                else
                    cout<<",";
            }
            cout<<"]\n";
        }
    }
    return 0;
}

