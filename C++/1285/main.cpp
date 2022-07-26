//
//  main.cpp
//  1285
//
//  Created by 홍승완 on 2022/07/25.
//

//
//  main.cpp
//  19942
//
//  Created by 홍승완 on 2022/07/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;
int n;
int maps[21][21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='H'){ //위
                maps[i][j]=1;
            }
            else maps[i][j]=0;//아래
        }
    }
    return 0;
}
