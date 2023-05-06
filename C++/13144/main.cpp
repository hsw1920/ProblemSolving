//
//  main.cpp
//  13144
//
//  Created by 홍승완 on 2023/05/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>v(100001,0);
int visited[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    
    int ed=0;
    long long res=0;
    for(int st=0;st<n;st++){
        while(ed<n){
            if(visited[v[ed]])break;
            visited[v[ed]]=1;
            ed++;
        }
        res+=(ed-st);
        visited[v[st]]=0;
    }
    cout<<res<<"\n";
    return 0;
}
