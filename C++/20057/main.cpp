//
//  main.cpp
//  20057
//
//  Created by 홍승완 on 2022/10/28.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maps[500][500];
int visited[500][500];
int n;
int sx,sy;
int res=0;

void goLeft(int cx, int cy){
    //y의 모래양구하고 없애기
    int curSend = maps[cx][cy-1];
    maps[cx][cy-1]=0;
    
    int p1 = curSend/100;
    int p2 = curSend*2/100;
    int p5 = curSend*5/100;
    int p7 = curSend*7/100;
    int p10 = curSend*10/100;
    int a = curSend-(p1+p2+p7+p10)*2-p5; // 나머지 모래
    
    if(cy-2<0){
        res+=a;
    } else {
        maps[cx][cy-2]+=a;
    }
    
    
    if(cy-3<0){
        res+=p5;
    }else {
        maps[cx][cy-3]+=p5;
    }
    
    if(cx-1<0||cy-2<0){
        res+=p10;
    }else {
        maps[cx-1][cy-2]+=p10;
    }
    if(cx+1>n-1||cy-2<0){
        res+=p10;
    }else {
        maps[cx+1][cy-2]+=p10;
    }
    
    if(cx-1<0||cy-1<0){
        res+=p7;
    }else {
        maps[cx-1][cy-1]+=p7;
    }
    if(cx+1>n-1||cy-1<0){
        res+=p7;
    }else {
        maps[cx+1][cy-1]+=p7;
    }
    
    if(cx-2<0||cy-1<0){
        res+=p2;
    }else {
        maps[cx-2][cy-1]+=p2;
    }
    if(cx+2>n-1||cy-1<0){
        res+=p2;
    }else {
        maps[cx+2][cy-1]+=p2;
    }
    
    if(cx-1<0){
        res+=p1;
    }else {
        maps[cx-1][cy]+=p1;
    }
    if(cx+1>n-1){
        res+=p1;
    }else {
        maps[cx+1][cy]+=p1;
    }

}
void goDown(int cx, int cy){
    //y의 모래양구하고 없애기
    int curSend = maps[cx+1][cy];
    maps[cx+1][cy]=0;
    
    int p1 = curSend/100;
    int p2 = curSend*2/100;
    int p5 = curSend*5/100;
    int p7 = curSend*7/100;
    int p10 = curSend*10/100;
    int a = curSend-(p1+p2+p7+p10)*2-p5; // 나머지 모래
    
    if(cx+2>n-1){
        res+=a;
    } else {
        maps[cx+2][cy]+=a;
    }
    
    if(cx+3>n-1){
        res+=p5;
    }else {
        maps[cx+3][cy]+=p5;
    }
    
    if(cx+2>n-1||cy-1<0){
        res+=p10;
    }else {
        maps[cx+2][cy-1]+=p10;
    }
    if(cx+2>n-1||cy+1>n-1){
        res+=p10;
    }else {
        maps[cx+2][cy+1]+=p10;
    }
    
    if(cx+1>n-1||cy-1<0){
        res+=p7;
    }else {
        maps[cx+1][cy-1]+=p7;
    }
    if(cx+1>n-1||cy+1>n-1){
        res+=p7;
    }else {
        maps[cx+1][cy+1]+=p7;
    }
    
    if(cx+1>n-1||cy-2<0){
        res+=p2;
    }else {
        maps[cx+1][cy-2]+=p2;
    }
    if(cx+1>n-1||cy+2>n-1){
        res+=p2;
    }else {
        maps[cx+1][cy+2]+=p2;
    }
    
    if(cy-1<0){
        res+=p1;
    }else {
        maps[cx][cy-1]+=p1;
    }
    if(cy+1>n-1){
        res+=p1;
    }else {
        maps[cx][cy+1]+=p1;
    }
}
void goRight(int cx, int cy){
    //y의 모래양구하고 없애기
    int curSend = maps[cx][cy+1];
    maps[cx][cy+1]=0;
    
    int p1 = curSend/100;
    int p2 = curSend*2/100;
    int p5 = curSend*5/100;
    int p7 = curSend*7/100;
    int p10 = curSend*10/100;
    int a = curSend-(p1+p2+p7+p10)*2-p5; // 나머지 모래
    
    if(cy+2>n-1){
        res+=a;
    } else {
        maps[cx][cy+2]+=a;
    }
    
    if(cy+3>n-1){
        res+=p5;
    }else {
        maps[cx][cy+3]+=p5;
    }
    
    if(cx-1<0||cy+2>n-1){
        res+=p10;
    }else {
        maps[cx-1][cy+2]+=p10;
    }
    if(cx+1>n-1||cy+2>n-1){
        res+=p10;
    }else {
        maps[cx+1][cy+2]+=p10;
    }
    
    if(cx-1<0||cy+1>n-1){
        res+=p7;
    }else {
        maps[cx-1][cy+1]+=p7;
    }
    if(cx+1>n-1||cy+1>n-1){
        res+=p7;
    }else {
        maps[cx+1][cy+1]+=p7;
    }
    
    if(cx-2<0||cy+1>n-1){
        res+=p2;
    }else {
        maps[cx-2][cy+1]+=p2;
    }
    if(cx+2>n-1||cy+1>n-1){
        res+=p2;
    }else {
        maps[cx+2][cy+1]+=p2;
    }
    
    if(cx-1<0){
        res+=p1;
    }else {
        maps[cx-1][cy]+=p1;
    }
    if(cx+1>n-1){
        res+=p1;
    }else {
        maps[cx+1][cy]+=p1;
    }
}
void goUp(int cx, int cy){
    //y의 모래양구하고 없애기
    int curSend = maps[cx-1][cy];
    maps[cx-1][cy]=0;
    
    int p1 = curSend/100;
    int p2 = curSend*2/100;
    int p5 = curSend*5/100;
    int p7 = curSend*7/100;
    int p10 = curSend*10/100;
    int a = curSend-(p1+p2+p7+p10)*2-p5; // 나머지 모래
    
    if(cx-2<0){
        res+=a;
    } else {
        maps[cx-2][cy]+=a;
    }
    
    if(cx-3<0){
        res+=p5;
    }else {
        maps[cx-3][cy]+=p5;
    }
    
    if(cx-2<0||cy+1>n-1){
        res+=p10;
    }else {
        maps[cx-2][cy+1]+=p10;
    }
    if(cx-2<0||cy-1<0){
        res+=p10;
    }else {
        maps[cx-2][cy-1]+=p10;
    }
    
    if(cx-1<0||cy+1>n-1){
        res+=p7;
    }else {
        maps[cx-1][cy+1]+=p7;
    }
    if(cx-1<0||cy-1<0){
        res+=p7;
    }else {
        maps[cx-1][cy-1]+=p7;
    }
    
    if(cx-1<0||cy+2>n-1){
        res+=p2;
    }else {
        maps[cx-1][cy+2]+=p2;
    }
    if(cx-1<0||cy-2<0){
        res+=p2;
    }else {
        maps[cx-1][cy-2]+=p2;
    }
    
    if(cy-1<0){
        res+=p1;
    }else {
        maps[cx][cy-2]+=p1;
    }
    if(cy+1>n-1){
        res+=p1;
    }else {
        maps[cx][cy+1]+=p1;
    }
}
int cnt=0;

void tonado(){
    int cx,cy;
    cx=sx,cy=sy;
    int idx=1;
    while(1){
        
        for(int i=0;i<2*idx-1;i++){
            if(cy-1<0)return;
            goLeft(cx,cy);
            cy--;

        }
        
        for(int i=0;i<2*idx-1;i++){
            if(cx>=n)return;
            goDown(cx,cy);
            cx++;
            
        }
        
        for(int i=0;i<2*idx;i++){
            if(cy>=n)return;
            goRight(cx,cy);
            cy++;
            
        }
        
        for(int i=0;i<2*idx;i++){
            if(cx<0)return;
            goUp(cx,cy);
            cx--;
            
        }
        
        idx++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
    
    // 시작지점
    sx=sy=n/2;
    // <- 2 4 6 8
    // 아래 2 4 6 8
    // -> 3 5 7 9
    // 위 3 5 7 9
    tonado();
    
    cout<<res<<"\n";
    
    return 0;
}
