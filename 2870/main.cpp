//
//  main.cpp
//  2870
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int n;
vector<string>v;
bool cmp(string a, string b){
//    if(a.size()==b.size()){
//        for(int i=0;i<a.size();i++){
//            if(a[i]==b[i])
//                continue;
//            else if(a[i]<b[i])
//                return a[i]<b[i];
//            else
//                return a[i]>b[i];
//        }
//    }
//    else {
//        return a.size() < b.size();
//    }
//    return a<b;
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}
int main() {
    
    cin>>n;
    string str;
    string num="";
    for(int i=0;i<n;i++){
        cin>>str;
        for(int i=0;i<str.size();i++){
            num="";
            if(str[i]>='0'&&str[i]<='9'){
                num=str[i];
                int idx=i+1;
                while(idx<str.size()&&str[idx]>='0'&&str[idx]<='9'){
                    num+=str[idx];
                    idx++;
                }
                
                int idx_first=0;
                for(int j=0;j<num.size();j++){
                    if(num[j]=='0'){
                        idx_first=j+1;
                    }
                    else{
                        break;
                    }
                }
                string tmp="";
                for(int j=idx_first;j<num.size();j++){
                    tmp+=num[j];
                }
                if(tmp=="")tmp="0";
                v.push_back(tmp);
                
                i=idx-1;
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
    
    return 0;
}
