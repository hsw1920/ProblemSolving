//
//  main.cpp
//  13413
//
//  Created by 홍승완 on 2022/10/24.
//

#include <iostream>

using namespace std;

int t,n;
string a,b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    
    while(t--){
        cin>>n;
        cin>>a;
        cin>>b;
        int ax,ay,bx,by,res;
        ax=ay=bx=by=res=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(a[i]=='B'){ax++;by++;}
                else {ay++;bx++;}
            }
        }
        while(ax>0&&ay>0&&bx>0&&by>0){
            ax--;ay--;bx--;by--;
            res++;
        }
        while(ax>0){
            ax--;by--;
            res++;
        }
        while(ay>0){
            ay--;bx--;
            res++;
        }
        
        cout<<res<<"\n";
    }
    
    return 0;
}
