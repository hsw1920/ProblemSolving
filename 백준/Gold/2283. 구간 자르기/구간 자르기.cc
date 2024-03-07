//
//  main.cpp
//  2230
//
//  Created by 홍승완 on 2024/03/06.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int st,ed;
}Line;

int N,K,A,B;
int sum=0;
Line line[1001];
int len[1000001]={0,};
int psum[1000001]={0,};
int getSum(int a, int b){
    int res=0;
    for(auto k: line){
        if(b<=k.st){
            continue;
        }
        else if(a<=k.st&&b>k.st&&b<k.ed){
            res+=(b-k.st);
        }
        else if(a<=k.st&&b>k.ed){
            res+=(k.ed-k.st);
        }
        else if(a>=k.st&&a<=k.ed && b<k.ed){
            res+=(b-a);
        }
        else if(a>=k.st&&a<=k.ed && b>k.ed){
            res+=(k.ed-a);
        }
        else if(a>k.ed){
            continue;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>N>>K;
    
    for(int i=0;i<N;i++){
        // 왼쪽, 오른쪽 끝점
        cin>>line[i].st>>line[i].ed;
        for(int st=line[i].st+1;st<=line[i].ed;st++){
            len[st]+=1;
        }
        
        sum+=(line[i].ed-line[i].st);
        if(i==0)continue;
    }
    
    for(int i=1;i<=1000000;i++){
        psum[i]=psum[i-1]+len[i];
    }
    
    if(sum<K){
        cout<<"0 0\n";
        return 0;
    }
    sum=0;
    // 임의의 A,B를 정한다.
    // 각 구간에서 A,B사이에 포함되지 않은 부분을 모두 잘라냈을 때
    // 남는 부분의 길이가 총합이 K가 되도록해라.
    // A,B가 여럿 존재할 때는 A가 가장 작은걸 출력, 그거도 여러개면 B가 작은것 출력
    
    // A,B 양끝점은 각 100만 -> 100만 O(N) 가능 -> 투포인터 ㅇㅋ
    // 왼쪽에서 오른쪽가는게 무조건 유리(1번만 찾으면 되기때문)
    
    for(A=0;A<=1000000;A++){
        
        // 잘린부분 총합을 구해야함.
        //그리고 K랑 비교해야함
        // 1. 잘린부분이 K보다 클때
        // 2. K보다 작을 때
        // 3. K와 같을 때 -> 분기
        if(psum[B]-psum[A]==K){
            cout<<A<<" "<<B<<"\n";
            break;
        } else if(psum[B]-psum[A]>K){
            continue;
        } else if(psum[B]-psum[A]<K) {
            while(psum[B]-psum[A]<K){
                B++;
            }
        }
        
        if(psum[B]-psum[A]==K){
            cout<<A<<" "<<B<<"\n";
            return 0;
        }
    }
    return 0;
}
