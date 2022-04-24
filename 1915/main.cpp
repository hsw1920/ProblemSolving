//
//  main.cpp
//  1915
//
//  Created by 홍승완 on 2022/04/24.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


int arr[1001][1001];





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    string str;
    
    cin>>n>>m;
    
    for(int i = 1; i <=n;i++){
        cin>>str;
        for(int j = 0 ;j < m ; j++){
            arr[i][j+1] = str[j]-'0';
        }
    }
    int res = 0;
    for(int i = 1 ; i <= n; i ++){
        for(int j = 1 ; j <= m; j++){
            
            if(arr[i][j] != 0){
                arr[i][j] = min(min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1])+1;
                res = max(arr[i][j],res);
            }
        }
    }

    cout<<res*res;

    return 0;
}
