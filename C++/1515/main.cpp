//
//  main.cpp
//  1515
//
//  Created by 홍승완 on 2022/11/05.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string s;
    cin>>s;
    int num = 1;
    int i=0;
    
    while(i<s.size()){
        string tmp = to_string(num); //
        int k= tmp.size();
        while(k){
            string nxt = s.substr(i,k); // 13 123
            int chk=0;
            int s=0;
            int ss=0;
            for(int j=0;j<nxt.size();j++){
                s=ss;
                while(s<tmp.size()){
                    if(nxt[j]==tmp[s]){
                        ss=s+1;
                        chk++;
                        break;
                    }
                    s++;
                }
            }
            if(chk==nxt.size()){
                i+=chk;
                break;
            }
            k--;
        }
        num++;
    }
    cout<<num-1<<"\n";
    
    return 0;
}
