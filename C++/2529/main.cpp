//
//  main.cpp
//  2529
//
//  Created by 홍승완 on 2022/07/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
int visited[10];
int n;
vector<char>op;
vector<string>num;

void init(){
    for(int i=0;i<10;i++)
        visited[i]=0;
}
void dfs(string x,int k){
    long long sz=x.size()-1;
    if(k==n){
        num.push_back(x);
        return;
    }
    for(int i=0;i<10;i++){
        if(visited[i]==0){
            //다음수가 1의자리보다 작아야함
            if(op[k]=='>'&&to_string(i)<to_string((x[sz]-'0')%10)){
                visited[i]=1;
                dfs(x+to_string(i),k+1);
                visited[i]=0;
            }
            //다음수가 1의자리보다 커야함
            else if(op[k]=='<'&&to_string(i)>to_string((x[sz]-'0')%10)){
                visited[i]=1;
                dfs(x+to_string(i),k+1);
                visited[i]=0;
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    char tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        op.push_back(tmp);
    }
    for(int i=0;i<10;i++){
        init();
        visited[i]=1;
        dfs(to_string(i),0);
        visited[i]=0;
    }
    sort(num.begin(),num.end());
//    for(auto i : num){
//        cout<<i<<"\n";
//    }
    cout<<num[num.size()-1]<<"\n"<<num[0]<<"\n";
    
    return 0;
}
