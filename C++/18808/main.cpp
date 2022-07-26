//
//  main.cpp
//  18808
//
//  Created by 홍승완 on 2022/05/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k,r,c;
// 스티커를 저장할 필요 없이 바로 붙여버리면 됨
int stk[10][10]={0,};
int maps[40][40]={0,};
void init_stk(){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            stk[i][j]=0;
}

//회전 X
bool attach0(){
    for(int i=0;i<n-(r-1);i++){
        for(int j=0;j<m-(c-1);j++){
            int chk=0;
            //스티커 붙일 수 있는지
            for(int h=i;h<i+r;h++){
                for(int w=j;w<j+c;w++){
                    //붙일 수 없을 때
                    if(maps[h][w]==1 && stk[h-i][w-j]==1){
                        chk=1;
                    }
                }
            }
            //붙일 수 있으면
            if(chk==0){
                //해당 좌표에 붙여버리면 됨
                for(int h=i;h<i+r;h++){
                    for(int w=j;w<j+c;w++){
                        if(maps[h][w]==0)
                            maps[h][w]=stk[h-i][w-j];
                    }
                }
                return true;
            }
        }
    }
    return false;
}

//90도 회전
// 세로(r) / 가로(c)
// 가로정,세로역
bool attach1(){
    for(int i=0;i<n-(c-1);i++){
        for(int j=0;j<m-(r-1);j++){
            int chk=0;
            //스티커 붙일 수 있는지
            for(int h=i;h<i+c;h++){
                for(int w=j;w<j+r;w++){
                    //붙일 수 없을 때
                    if(maps[h][w]==1 && stk[(r-1)-(w-j)][h-i]==1){
                        chk=1;
                    }
                }
            }
            //붙일 수 있으면
            if(chk==0){
                //해당 좌표에 붙여버리면 됨
                for(int h=i;h<i+c;h++){
                    for(int w=j;w<j+r;w++){
                        if(maps[h][w]==0)
                            maps[h][w]=stk[(r-1)-(w-j)][h-i];
                    }
                }
                return true;
            }
        }
    }
    return false;
}

// 180도 회전시
bool attach2(){
    for(int i=0;i<n-(r-1);i++){
        for(int j=0;j<m-(c-1);j++){
            int chk=0;
            //스티커 붙일 수 있는지
            for(int h=i;h<i+r;h++){
                for(int w=j;w<j+c;w++){
                    //붙일 수 없을 때
                    if(maps[h][w]==1 && stk[(r-1)-(h-i)][(c-1)-(w-j)]==1){
                        chk=1;
                    }
                }
            }
            //붙일 수 있으면
            if(chk==0){
                //해당 좌표에 붙여버리면 됨
                for(int h=i;h<i+r;h++){
                    for(int w=j;w<j+c;w++){
                        if(maps[h][w]==0)
                            maps[h][w]=stk[(r-1)-(h-i)][(c-1)-(w-j)];
                    }
                }
                return true;
            }
        }
    }
    return false;
}

//270도 회전
bool attach3(){
    for(int i=0;i<n-(c-1);i++){
        for(int j=0;j<m-(r-1);j++){
            int chk=0;
            //스티커 붙일 수 있는지
            for(int h=i;h<i+c;h++){
                for(int w=j;w<j+r;w++){
                    //붙일 수 없을 때
                    if(maps[h][w]==1 && stk[w-j][(c-1)-(h-i)]==1){
                        chk=1;
                    }
                }
            }
            //붙일 수 있으면
            if(chk==0){
                //해당 좌표에 붙여버리면 됨
                for(int h=i;h<i+c;h++){
                    for(int w=j;w<j+r;w++){
                        if(maps[h][w]==0)
                            maps[h][w]=stk[w-j][(c-1)-(h-i)];
                    }
                }
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int q=0;q<k;q++){
        cin>>r>>c;
        //스티커 초기화
        init_stk();
        //스티커 입력
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>stk[i][j];
            }
        }
        
        //스티커 입력 받았으면 바로 붙여야함
        if(attach0()){ //회전 X
            continue;
        }
        else if(attach1()){ //90도 회전
            continue;
        }
        else if(attach2()){ //180도 회전
            continue;
        }
        else if(attach3()){ //270도 회전
            continue;
        }
        
    }
    // 스티커가 붙은 칸 개수 세서 출력
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]==1)
                cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
