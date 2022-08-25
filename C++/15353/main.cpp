//
//  main.cpp
//  15353
//
//  Created by 홍승완 on 2022/08/25.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[10001],b[10001],c[10001];
    string q,w;
    cin>>q>>w;
    for(int i=0;i<q.size();i++){
        a[i]=q[q.size()-1-i]-'0';
    }
    for(int i=0;i<w.size();i++){
        b[i]=w[w.size()-1-i]-'0';
    }
    int up=0;
    for(int i=0;i<max(q.size(),w.size());i++){
        if(up==0){
            if(a[i]+b[i]>9){
                up=1;
                c[i]=a[i]+b[i]-10;
            }
            else{
                c[i]=a[i]+b[i];
            }
        }
        else if(up==1){
            if(a[i]+b[i]+1>9){
                up=1;
                c[i]=a[i]+b[i]+1-10;
            }
            else {
                up=0;
                c[i]=a[i]+b[i]+1;
            }
        }
    }
    
    if(up==1)cout<<1;
    
    for(int i=max(q.size(),w.size())-1;i>=0;i--)
        cout<<c[i];
    cout<<"\n";
    return 0;
}
