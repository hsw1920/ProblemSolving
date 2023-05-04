//
//  main.cpp
//  2847
//
//  Created by 홍승완 on 2023/05/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n개의 레벨 존재 -> 클리어할 떄마다 점수
// 점수의 합으로 순위매김
// 레벨을 난이도 순으로 배치
// 실수로 쉬운 레벨이 어려운 레벨보다 점수를 많이 받는 경우가 있음
// 특정 레벨의 점수를 감소시켜야함
// 몇번 감소시키면 되는가?, 1점감소가 1번임
// 항상 답은 존재함, 방법이 여러개라면 점수를 내리는것을 최소화하는 방법으로 해야함

int n;
int arr[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int prev=arr[n-1];
    int res=0;
    for(int i=n-2;i>=0;i--){
        int cur = arr[i];
        int diff=abs(prev-cur)+1;
        if(cur>=prev){
            res+=diff;
            prev=cur-diff;
        } else {
            prev=cur;
        }
    }
    cout<<res<<"\n";
    return 0;
}
