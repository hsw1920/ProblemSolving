//
//  main.cpp
//  1062
//
//  Created by 홍승완 on 2022/08/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n,k;
int alp[26]={0,};
int ans = 0;
vector<char>str[51];
void dfs(int alpha, int cnt) {
    if(cnt==0){
        int res = 0;
        for(int i=0;i<n;i++){
            bool chk=false;
            for(int j=0;j<str[i].size();j++){
                if(alp[str[i][j]-'a']==1){
                    chk=true;
                    break;
                }
            }
            if(!chk) res++;
        }
        ans=max(ans,res);
        return ;
    }
    
    for(int i=alpha;i<26;i++){
        if(alp[i]==1){
            // i를 없애고
            alp[i]=0;
            dfs(i,cnt-1);
            //다시 i를 살리고
            alp[i]=1;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // a n t i c
    cin>>n>>k;
    int ccc[26]={0,};
    int sum=0;
    for(int q=0;q<n;q++){
        string tmp;
        cin>>tmp;
        for(int i=4;i<tmp.size()-4;i++){
            if(tmp[i]!='a' &&
               tmp[i]!='n' &&
               tmp[i]!='t' &&
               tmp[i]!='i' &&
               tmp[i]!='c' ) {
                alp[tmp[i]-'a']=1;
                ccc[tmp[i]-'a']=1;
            }
            str[q].push_back(tmp[i]);
        }
    }
    
    for(int i=0;i<26;i++) {
        if(ccc[i]==1) sum++;
    }
    
    if(k>=sum+5){
        cout<<n;return 0;}
    if(k<5) {cout<<0; return 0;}
    if(k==26){cout<<n; return 0;}
    
    dfs(0,k-5);
    cout<<ans<<"\n";
    return 0;
    
}
