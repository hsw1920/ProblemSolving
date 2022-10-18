//
//  main.cpp
//  1439
//
//  Created by 홍승완 on 2022/10/18.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
string str;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    int idx=0;
    
    int c1=0, c2=0;
    int chk=0;
    while(idx!=str.size()){
        chk=0;
        while(str[idx]=='0'&&idx<str.size()){
            idx++;
            chk=1;
        }
        if(chk==1)c1++;
        if(idx==str.size())break;
        
        chk=0;
        while(str[idx]=='1'&&idx<str.size()){
            idx++;
            chk=1;
        }
        if(chk==1)c2++;
        if(idx==str.size())break;
    }
    cout<<min(c1,c2)<<"\n";
    return 0;
}
