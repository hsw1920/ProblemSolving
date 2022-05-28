//
//  main.cpp
//  21608
//
//  Created by 홍승완 on 2022/05/28.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// 교실 n*n, 학생 n^2명, r행 c열
// 조건 1, 2, 3각각 구현할 것 , n<=20이라 맘대로 다 가능할듯
int n,r,c;
int st[401][5]; // 학생과 좋아하는 학생
int maps[21][21]={0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
// 비어있는칸?
void condition(int stNum){
    int resX=21,resY=21;
    int cnt=0;
    // 좋아하는 학생 인접 최대개수
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(maps[i][j]==0){
                int tmp=0; // 좋아하는 학생 인접 수
                for(int q=0;q<4;q++){
                    int xx=i+dx[q];
                    int yy=j+dy[q];
                    if(xx>=1&&xx<=n&&yy>=1&&yy<=n){
                    for(int k=1;k<=4;k++){
                        if(st[stNum][k]==maps[xx][yy]){
                                tmp++;
                            }
                        }
                    }
                }
                cnt=max(cnt,tmp);
            }
        }
    }
    
    // cnt인곳 중에서 인접칸중 빈칸 많은곳
    // 그 중에서 행렬번호가 최소인칸 고르면됨
    int blank=0; // 빈칸 최대값 구할거임
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(maps[i][j]==0){
                int tmp=0; // 좋아하는 학생 인접 수
                for(int q=0;q<4;q++){
                    int xx=i+dx[q];
                    int yy=j+dy[q];
                    if(xx>=1&&xx<=n&&yy>=1&&yy<=n){
                        for(int k=1;k<=4;k++){
                            if(st[stNum][k]==maps[xx][yy]){
                                tmp++;
                            }
                        }
                    }
                }
                if(tmp==cnt){
                    int ttmp=0;
                    //빈칸 볼거임
                    for(int q=0;q<4;q++){
                        int xx=i+dx[q];
                        int yy=j+dy[q];
                        if(xx>=1&&xx<=n&&yy>=1&&yy<=n){
                            if(maps[xx][yy]==0){
                                ttmp++;
                            }
                        }
                    }
                    blank=max(blank,ttmp);
                }
                
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(maps[i][j]==0){
                int tmp=0; // 좋아하는 학생 인접 수
                for(int q=0;q<4;q++){
                    int xx=i+dx[q];
                    int yy=j+dy[q];
                    if(xx>=1&&xx<=n&&yy>=1&&yy<=n){
                        for(int k=1;k<=4;k++){
                            if(st[stNum][k]==maps[xx][yy]){
                                tmp++;
                            }
                        }
                    }
                }
                if(tmp==cnt){
                    int ttmp=0;
                    //빈칸 볼거임
                    for(int q=0;q<4;q++){
                        int xx=i+dx[q];
                        int yy=j+dy[q];
                        if(xx>=1&&xx<=n&&yy>=1&&yy<=n){
                            if(maps[xx][yy]==0){
                                ttmp++;
                            }
                        }
                    }
                    //이제 행렬 최소칸을 찾아서 갱신함.
                    if(ttmp==blank){
                        // 행 > 열
                        // 행작으면 무조건 바꿈
                        if(resX>i){
                            resX=i,resY=j;
                        }
                        else if(resX==i && resY>j){
                            // 행이 같으면 열 작을때 바꿈
                            resX=i,resY=j;
                        }
                    }
                    
                }

            }
            
        }
    }
    
    maps[resX][resY]=st[stNum][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n*n;i++){
        for(int j=0;j<=4;j++){
            cin>>st[i][j]; // 0번째에 해당하는 학생
        }
    }
    // 각 학생들에 대해서 모두 자리배치

    for(int i=0;i<n*n;i++){
        // 조건 123 고려
        condition(i);
    }
    
    int res=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp=0; // 좋아하는 학생 인접 수
            for(int q=0;q<4;q++){
                int xx=i+dx[q];
                int yy=j+dy[q];
                if(xx>=1&&xx<=n&&yy>=1&&yy<=n){
                    // 해당칸에 좋아하는 학생수
                    for(int k=1;k<=4;k++){
                        
                        //maps[i][j] 구해야 함
                        int target;
                        for(int r=0;r<n*n;r++){
                            if(st[r][0]==maps[i][j])
                                target=r;
                        }
                        if(st[target][k]==maps[xx][yy]){
                            tmp++;
                        }
                    }
                }
            }
            if(tmp>0){
                tmp--;
                int tot=1;
                while(tmp--){
                    tot*=10;
                }
                res+=tot;
            }
        }
    }
    
    cout<<res;
    
    return 0;
}

