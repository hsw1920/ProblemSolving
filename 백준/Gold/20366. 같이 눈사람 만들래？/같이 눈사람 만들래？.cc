//
//  main.cpp
//  2230
//
//  Created by 홍승완 on 2024/03/06.
//

#include <bits/stdc++.h>

using namespace std;
// N개의 눈덩이가 있음.
///각 눈덩이의 지름은 H이다.
///눈사람의 키는 눈덩이 2개의 지름의 합과 같다.
///눈덩이 N개중 서로 다른 4개를 골라서 총 2개를 만든다.
///눈사람의 키의 차이가 작은 경우를 구하라.
/// (키 차이의 최솟값 구하고 출력)
/// N<=600, H<=1e9

int n;
int H[601]; // 최대 600개의 눈덩이

typedef struct {
    int val,a,b;
}S;

vector<S>snowman;

bool compare(S a, S b){
    return a.val<b.val;
}

bool isValid(S a, S b){
    if(a.a==b.a||a.a==b.b||a.b==b.a||a.b==b.b) return false;
    return true;
}

int hsub(S a, S b){
    return abs(a.val-b.val);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>H[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            snowman.push_back(S{H[i]+H[j],i,j});
        }
    }
    sort(snowman.begin(),snowman.end(),compare);
    
    int res=2e9;
    int st=0,ed=1;
    
    for(st=0;st<snowman.size();st++){
        // 눈사람 조합 가능하고 최소이면
        if(isValid(snowman[st], snowman[ed]) && res>hsub(snowman[st], snowman[ed])){
            res=hsub(snowman[st], snowman[ed]);
            ed++;
        }
        else {
            if(st<ed-1){
                continue;
            }
            else {
                ed++;
            }
        }
        
        if(isValid(snowman[st], snowman[ed]) && res>hsub(snowman[st], snowman[ed])){
            res=hsub(snowman[st], snowman[ed]);
        }
    }
                    
    cout<<res<<"\n";
    return 0;
}
