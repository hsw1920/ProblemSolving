//
//  main.cpp
//  13460
//
//  Created by 홍승완 on 2022/03/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pint pair<int,int>
using namespace std;
int n,m;
char map[11][11];
int xr,yr,xb,yb;
int xh,yh;
int cnt=1e9;
pair<pair<pint,pint>,int> goR(pair<pair<pint,pint>,int> q){
    int xR,yR,xB,yB;
    xR=q.first.first.first;
    yR=q.first.first.second;
    xB=q.first.second.first;
    yB=q.first.second.second;
    int res = q.second;
    //B가 더 오른쪽에 있을 때
    if(yR<yB){
        //B가 먼저 움직임 -> #을 만나기전까지
        while(map[xB][yB+1]!='#' && yB<m){
            yB++;
            //구멍에 들어가면 없애기
            if(xh==xB&&yh==yB){
                xB=0;yB=0;
                res=-1;
            }
        }
        while(map[xR][yR+1]!='#' && yR<m){
            if(xR==xB){
                if(yR+1==yB)
                    break;
            }
            yR++;
            //구멍에 들어가면 없애기
            if(xR==xh&&yR==yh){
                break;
            }
        }
    }
    //R이 더 오른쪽에 있을 때
    else{
        //R이 먼저 움직임 -> #을 만나기전까지
        while(map[xR][yR+1]!='#' && yR<m){
            yR++;
            if(xR==xh&&yR==yh){
                break;
            }
        }
        while(map[xB][yB+1]!='#' && yB<m){
            if(xR!=xh||yR!=yh){
                if(xR==xB){
                    if(yB+1==yR)
                        break;
                }
            }
            yB++;
            //구멍에 들어가면 없애기
            if(xh==xB&&yh==yB){
                xB=0;yB=0;
                res=-1;
            }
        }
    }
    
    return {{{xR,yR},{xB,yB}},res};
}
pair<pair<pint,pint>,int> goL(pair<pair<pint,pint>,int> q){
    int xR,yR,xB,yB;
    xR=q.first.first.first;
    yR=q.first.first.second;
    xB=q.first.second.first;
    yB=q.first.second.second;
    int res = q.second;
    //B가 더 왼쪽에 있을 때
    if(yR>yB){
        //B가 먼저 움직임 -> #을 만나기전까지
        while(map[xB][yB-1]!='#'&& yB>0){
            yB--;
            //구멍에 들어가면 없애기
            if(xh==xB&&yh==yB){
                xB=0;yB=0;
                res=-1;
            }
        }
        while(map[xR][yR-1]!='#' &&yR>0){
            if(xR==xB){
                if(yR-1==yB)
                    break;
            }
            yR--;
            //구멍에 들어가면 없애기
            if(xR==xh&&yR==yh){
                break;
            }
        }
    }
    //R이 더 왼쪽에 있을 때
    else{
        //R이 먼저 움직임 -> #을 만나기전까지
        while(map[xR][yR-1]!='#'&& yR>0){
            yR--;
            if(xR==xh&&yR==yh){
                break;
            }
        }
        while(map[xB][yB-1]!='#'&&yB>0){
            if(xR!=xh||yR!=yh){
                if(xR==xB){
                    if(yB-1==yR)
                        break;
                }
            }
            yB--;
            //구멍에 들어가면 없애기
            if(xh==xB&&yh==yB){
                xB=0;yB=0;
                res=-1;
            }
        }
    }
    
    return {{{xR,yR},{xB,yB}},res};
}
pair<pair<pint,pint>,int> goU(pair<pair<pint,pint>,int> q){
    int xR,yR,xB,yB;
    xR=q.first.first.first;
    yR=q.first.first.second;
    xB=q.first.second.first;
    yB=q.first.second.second;
    int res = q.second;
    //B가 더 위에 있을 때
    if(xR>xB){
        //B가 먼저 움직임 -> #을 만나기전까지
        while(map[xB-1][yB]!='#'&&xB>0){
            xB--;
            //구멍에 들어가면 없애기
            if(xh==xB&&yh==yB){
                xB=0;yB=0;
                res=-1;
            }
        }
        while(map[xR-1][yR]!='#'&&xR>0){
            if(yR==yB){
                if(xR-1==xB)
                    break;
            }
            xR--;
            //구멍에 들어가면 없애기
            if(xR==xh&&yR==yh){
                break;
            }
        }
    }
    //R이 더 위에 있을 때
    else{
        //R이 먼저 움직임 -> #을 만나기전까지
        while(map[xR-1][yR]!='#'&&xR>0){
            xR--;
            if(xR==xh&&yR==yh){
                break;
            }
        }
        while(map[xB-1][yB]!='#'&&xB>0){
            if(xR!=xh||yR!=yh){
                if(yR==yB){
                    if(xB-1==xR)
                        break;
                }
            }
            xB--;
            //구멍에 들어가면 없애기
            if(xh==xB&&yh==yB){
                xB=0;yB=0;
                res=-1;
            }
        }
    }
    return {{{xR,yR},{xB,yB}},res};
}
pair<pair<pint,pint>,int> goD(pair<pair<pint,pint>,int> q){
    int xR,yR,xB,yB;
    xR=q.first.first.first;
    yR=q.first.first.second;
    xB=q.first.second.first;
    yB=q.first.second.second;
    int res = q.second;
    //B가 더 아래에 있을 때
    if(xR<xB){
        //B가 먼저 움직임 -> #을 만나기전까지
        while(map[xB+1][yB]!='#'&&xB<n){
            xB++;
            //구멍에 들어가면 없애기
            if(xh==xB&&yh==yB){
                xB=0;yB=0;
                res=-1;
            }
        }
        while(map[xR+1][yR]!='#'&&xR<n){
            if(yR==yB){
                if(xR+1==xB)
                    break;
            }
            xR++;
            //구멍에 들어가면 없애기
            if(xR==xh&&yR==yh){
                break;
            }
        }
    }
    //R이 더 아래에 있을 때
    else{
        //R이 먼저 움직임 -> #을 만나기전까지
        while(map[xR+1][yR]!='#'&&xR<n){
            xR++;
            if(xR==xh&&yR==yh){
                break;
            }
        }
        while(map[xB+1][yB]!='#'&&xB<n){
            if(xR!=xh||yR!=yh){
                if(yR==yB){
                    if(xB+1==xR)
                        break;
                }
            }
            xB++;
            //구멍에 들어가면 없애기
            if(xh==xB&&yh==yB){
                xB=0;yB=0;
                res=-1;
            }
        }
    }
    return {{{xR,yR},{xB,yB}},res};
}
void bfs(){
    queue<pair<pair<pint,pint>,int>> q;
    q.push({{{xr,yr},{xb,yb}},0});
    while(!q.empty()){
        int xR,yR,xB,yB,res;
        xR=q.front().first.first.first;
        yR=q.front().first.first.second;
        xB=q.front().first.second.first;
        yB=q.front().first.second.second;
        res=q.front().second;
        q.pop();
        if(res==-1)continue;
        if(xR==xh&&yR==yh && res!=-1){
            cnt=min(cnt,res);
        }
        if(res==10)
            continue;
        if(res!=-1 && res<10){
            q.push(goR({{{xR,yR},{xB,yB}},res+1}));
            q.push(goD({{{xR,yR},{xB,yB}},res+1}));
            q.push(goL({{{xR,yR},{xB,yB}},res+1}));
            q.push(goU({{{xR,yR},{xB,yB}},res+1}));
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // .    #    0   R  B    //  최소 몇번만에 빨간 구슬을 구멍을통해 뺴내는지? 10번넘으면 -1출력
    // 빈칸  벽   구멍  빨 파     //  기울이기 함수 ==> 상하좌우 4^10 2^20 1000 1000 시간 ㄱㅊ   //  완탐..? ㄴㄴ..
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]=='R'){
                xr=i;yr=j;
                map[i][j]='.';
            }
            else if(map[i][j]=='B'){
                xb=i;yb=j;
                map[i][j]='.';
            }
            else if(map[i][j]=='O'){
                xh=i;yh=j;
            }
        }
    }
    bfs();
    if(cnt==1e9)
        cout<<-1;
    else
        cout<<cnt<<"\n";
    return 0;
}
