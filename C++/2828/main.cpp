//
//  main.cpp
//  2828
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,k;
int x1,x2,target,cnt=0;

void move_right(){
    x2++;
    x1++;
}
void move_left(){
    x1--;
    x2--;
}

int main() {
    cin>>n>>m;
    cin>>k;
    x1=1;
    x2=m;
    
    for(int i=0;i<k;i++){
        cin>>target;
        // 바구니에 사과가 떨어지면
        if(target>=x1&&target<=x2){
            continue;
        }
        else {
            // 사과가 바구니보다 왼쪽
            if(target<x1){
                while(target<x1){
                    move_left();
                    cnt++;
                }
            }
            // 사과가 바구니보다 오른쪽
            else if(target>x2){
                while(target>x2){
                    move_right();
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<"\n";
    
    // 이게 왜 dfs/bfs ?????
    return 0;
}
