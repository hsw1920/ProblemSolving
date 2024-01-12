//
//  main.cpp
//  4659
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

string str;

bool ch1(){
    int len=str.size();
    int chk=0;
    for(int i=0;i<len;i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            chk++;
        }
    }
    if(chk>0)
        return true;
    return false;
}

bool ch2(){
    int len=str.size();
    int chk=1,cur;
    int cnt=1;
    // 모음이 0
    if(str[0]=='a'||str[0]=='e'||str[0]=='i'||str[0]=='o'||str[0]=='u'){
        chk=0;
    }
    for(int i=1;i<len;i++){
        //모음
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            cur=0;
        }
        //자음
        else{
            cur=1;
        }
        
        if(chk==cur){
            cnt++;
            if(cnt==3)
                return false;
        }
        else {
            chk=cur;
            cnt=1;
        }
    }
    return true;
}

bool ch3(){
    int len=str.size();
    for(int i=1;i<len;i++){
        if(str[i]==str[i-1]){
            if(str[i]=='e'||str[i]=='o') continue;
            return false;
        }
    }
    return true;
}

int main() {
    
    while(1){
        cin>>str;
        if(str=="end")break;
        cout<<"<"<<str<<"> ";
        if(ch1()&&ch2()&&ch3()){
            cout<<"is acceptable.\n";
        }
        else {
            cout<<"is not acceptable.\n";
        }
    }
    return 0;
}
