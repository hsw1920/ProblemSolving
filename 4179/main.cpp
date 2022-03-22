//
//  main.cpp
//  4179
//
//  Created by 홍승완 on 2022/03/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pint pair<int,int>
using namespace std;

int r,c;

string maps[1001];
pint s,fire;
void bfs(){
    queue<pint>p;
    queue<pint>q;
    p.push()
}
int main() {
    cin>>r>>c;
    for(int i=0;i<r;i++){
        cin>>maps[i];
        for(int j=0;j<c;j++){
            if(maps[i][j]=='J')
                s={i,j};
            if(maps[i][j]='F')
                fire=maps[i][j];
        }
    }
    return 0;
}
