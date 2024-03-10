#include <bits/stdc++.h>

using namespace std;

int N,L,res=0;
int maps[101][101];
vector<vector<int>>load;
// 지도에서 지나갈 수 있는 길이 몇개?
// 길이한 한 행, 열 전부를 나타냄. 한쪽끝에서 한쪽끝


// 경사로 L을 어떻게 활용할 것인가
// 경사로는 낮은칸에 놓는다.
// 낮,높칸의 높이차는 반드시 1

// 일단 길 개수 200(100*2)
// 각 길을 갈 수 있는 경우의 수의 합를 구하라.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>N>>L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>maps[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        vector<int>tmp1,tmp2;
        for(int j=0;j<N;j++){
            tmp1.push_back(maps[i][j]);
            tmp2.push_back(maps[j][i]);
        }
        load.push_back(tmp1);
        load.push_back(tmp2);
    }
    
    for(auto k: load){
        vector<int> lod = k;
        int dp[101]={0,};
        dp[0]=1; // 초기값
        
        // 길 되는지 체킹해야함.!!
        int chk=0;
        for(int i=1;i<N;i++){
            int prev = lod[i-1]; // 이전값
            int cur = lod[i]; // 현재
            
            // 높이차 예외처리
            if(abs(prev-cur)>1){
                chk=-1;
                break;
            }
            
            // 같을 때
            if(prev==cur){
                dp[i]=dp[i-1]+1;
                //체크
            }
            
            // 현재가 클때 -> L활용해야함 (여긴 높이가 1차이)
            else if(prev<cur){
                // 경사로 놓을 수 있음
                if(dp[i-1]>=L){
                    dp[i]=1;
                    //체크
                }
                else{
                    // 경사로 못 놓음
                    chk=-1;
                    break;
                }
            }
            // 현재가 작을 때 -> 뒤를 확인해야함.
            else {
                // 경사로 놓을 자리가 없으면 컷
                if(i+L>N) {
                    chk=-1;
                    break;
                }
                // 이제 경사로는 놓을 수 있음.
                dp[i]=1;
                for(int w=i+1;w<i+L;w++){
                    int tmp_prev=lod[w-1];
                    int tmp_cur=lod[w];
                    if(tmp_cur==tmp_prev){
                        dp[w]=dp[w-1]+1;
                    }
                }
                
                // 경사로 진짜 놓을 수 있으면
                if(dp[i+L-1]==L){
                    dp[i+L-1]=0;
                    i=i+L-1;
                }
                else{
                    chk=-1;
                    break;
                }
            }
        }
        if(chk!=-1){
            res++;
        }
    }
    cout<<res<<"\n";
//    int lod[101]= {3,3,3,2,2,2};
        //수  // 1 1 1 2 2 3
    //dp // 1 2 3 1 2
    //      (dp가 L이상) (dp가 L이상)

    return 0;
}

