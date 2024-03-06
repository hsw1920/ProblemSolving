//
//  main.cpp
//  2230
//
//  Created by 홍승완 on 2024/03/06.
//

#include <bits/stdc++.h>

using namespace std;
int n,k,val,v[1000001],psum[1000001];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>val;
        if(val%2==0) {
            val=1;//짝수1
        } else{
            val=0;//홀수0
        }
        v[i]=val;
        
        if(i==0){
            psum[i]=val;
            continue;
        }
        psum[i]=psum[i-1]+val;
    }
    
    // 길이가 n, 수열있음.
    // 수열에서 원하는 위치의 수를 골라 k번 삭제 가능 -> (k번 삭제안해도됨.)
    // 수열에서 최대 k번 원소를 삭제해서 짝수로 이뤄진 연속부분수열중 가장 긴 길이를 구하자. -> psum 필요없음
    // 나이브하게 홀수를 삭제하는것이 유리함.
    // 나이브: 애초에 홀짝으로 배열에 넣기 -> 부분수열길이 - k가 최대길이.
    int res=0;
    int st=1,ed=2;
    if(psum[st]==1)res=1;
    
    // psum[ed]-psum[st-1] -> st부터 ed까지의 짝수의 개수
    // ed-st+1-k가 길어야함.
    // ed-st+1은 st~ed까지의 길이.
    // 가능한 범위는 ed를 계속 늘리면서 길이를 늘릴수있음.
    // 근데 ed-st+1이  psum[ed]-psum[st-1]+k 보다 크면 안됨.
    for(int st=1;st<=n;st++){
        //구간에서 짝수개수,            구간길이
        // 근데 그렇다고 ed를 계속은 못늘림. ed는 n까지만
        while(ed-st+1-k <= psum[ed]-psum[st-1] && ed<n){
            res=max(res,psum[ed]-psum[st-1]);
            ed++;
        }
        
        if(ed==n && ed-st+1-k <= psum[ed]-psum[st-1]) {
            res=max(res,psum[ed]-psum[st-1]);
        }
        
        if(ed==n){
            break;
        }
        // 그럼 여기서 ed가 n일때를 처리
        // 할필요가 없을듯? 가장 긴길이니까.
        
    }
    cout<<res<<"\n";
    // k==2
    // 10110001: v
    // 11233334: psum
    // ed-st+1-k가 psum[ed]-psum[st-1]보다 작을때까지만 ed를 늘릴 수 있음.
    
    return 0;
}
