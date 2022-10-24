//
//  main.cpp
//  5555
//
//  Created by 홍승완 on 2022/10/24.
//

#include <iostream>

using namespace std;

string target,s;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>target;
    cin>>n;
    int res=0;
    while(n--){
        
        cin>>s;
        for(int i=0;i<10;i++){
            s+=s[i];
        }
        if(s.find(target)!=string::npos){
            res++;
        }
    }
    cout<<res<<"\n";
    return 0;
}
