//
//  main.cpp
//  11723
//
//  Created by 홍승완 on 2022/08/24.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n,k;
string tmp;
int s[21]={0,};

void add(int k){
    s[k]=k;
}
void remove(int k){
    s[k]=0;
}
void check(int k){
    s[k] == k ? cout<<1<<"\n" : cout<<0<<"\n";
}
void toggle(int k){
    s[k] == k ? s[k]=0 : s[k]=k;
}
void all(){
    for(int i=1;i<21;i++)
        s[i]=i;
}
void emptys(){
    for(int i=0;i<20;i++)
        s[i]=0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        cin>>tmp;
        if(tmp == "add"){
            cin>>k;
            add(k);
        }
        else if(tmp == "remove"){
            cin>>k;
            remove(k);
        }
        else if(tmp == "check"){
            cin>>k;
            check(k);
        }
        else if(tmp == "toggle"){
            cin>>k;
            toggle(k);
        }
        else if (tmp=="all"){
            all();
        }
        else if(tmp=="empty"){
            emptys();
        }
    }
    return 0;
}
