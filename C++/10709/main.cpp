//
//  main.cpp
//  10709
//
//  Created by 홍승완 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int h,w;
char maps[101][101];
int t[101][101];
int main() {
    scanf("%d %d",&h,&w);
    getchar();
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%c",&maps[i][j]);
            t[i][j]=-1;
        }
        getchar();
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(maps[i][j]=='c'){
                int tmp=1;
                t[i][j]=0;
                int idx=j+1;
                while(maps[i][idx]!='c'&&idx<w){
                    t[i][idx++]=tmp++;
                }
                j=idx-1;
            }
        }
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
