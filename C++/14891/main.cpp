//
//  main.cpp
//  14891
//
//  Created by 홍승완 on 2022/05/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int k,n,d;
int t[4][8]; //톱니바퀴 4개

void rotate(int n, int d){
    //시계
    if(d==1){
        //오른쪽으로
        int tmp=t[n][7];
        for(int i=7;i>0;i--){
            t[n][i]=t[n][i-1];
        }
        t[n][0]=tmp;
    }
    //반시계
    else{
        //왼쪽으로
        int tmp=t[n][0];
        for(int i=0;i<7;i++){
            t[n][i]=t[n][i+1];
        }
        t[n][7]=tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //톱니바퀴 입력
    string tmp;
    for(int i=0;i<4;i++){
        cin>>tmp;
        for(int j=0;j<8;j++){
            t[i][j]=tmp[j]-'0';
        }
    }
    
    //몇 번 회전할지와
    cin>>k;
    for(int q=0;q<k;q++){
        cin>>n>>d; // 톱니바퀴 번호와 방향 입력
    
        // 상호작용하는 톱니 방향 정하기
        int dd,yy;
        if(d==1)
            yy=dd=-1;
        else
            yy=dd=1;
        
        // 돌리기전에 왼, 오의 맞물리는 경우 확인
        int d1=0,d2=0;
        
        //돌리는 톱니 왼쪽경우
        if(n>=2 && t[n-1][6]!=t[n-2][2]){
            d1=1;
        }
        //돌리는 톱니 오른쪽경우
        if(n<=3 && t[n-1][2]!=t[n][6]){
            d2=1;
        }
        
        // idx 2와 6이 맞 물리게 된다.
        // 일단 해당 번호를 방향에 맞추어 돌림
        rotate(n-1,d);
        
        // 이후 상호작용
        // 배열상 위쪽방향으로 NS에 따라 돌아가는 톱니
        
        // 해당 톱니보다 왼쪽것들 모두 돌려버림
        if(d1==1){
            for(int i=n-2;i>=0;i--){
                int cnt=0;
                //왼쪽을 돌리는데 오른쪽 톱니의 6번과
                //자신의 2번톱니가 다를때까지 돌린 반대방향으로 돌림
                
                if(t[i-1][2]!=t[i][6]){
                    cnt=1;
                }
                    
                
                rotate(i,dd);
                
                if(cnt==0)
                    break;
                else
                    dd*=(-1);
            }
        }
        dd=yy;
        if(d2==1){
            // 나머지도 아래쪽방향으로 NS에 따라 돌아가게 된다
            for(int i=n;i<4;i++){
                int cnt=0;
                //오른쪽을 돌리는데 왼쪽 톱니의 2번과
                //자신의 6번톱니가 다를때까지 돌린 반대방향으로 돌림
                if(t[i+1][6]!=t[i][2]){
                    cnt=1;
                }
                
                rotate(i,dd);
                
                if(cnt==0)
                    break;
                else
                    dd*=(-1);
            }
        }
    }
    
    // 회전 후 점수 합계 및 출력
    int sum=0;
    if(t[0][0]==1)sum+=1;
    if(t[1][0]==1)sum+=2;
    if(t[2][0]==1)sum+=4;
    if(t[3][0]==1)sum+=8;
    
    cout<<sum;
    return 0;
}
