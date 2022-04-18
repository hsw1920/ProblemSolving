//
//  main.cpp
//  2467
//
//  Created by 홍승완 on 2022/03/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long arr[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=0;
    int e=n-1;
    int res=2e9;
    int q,w;
    while(s<e){
        int a=arr[s];
        int b=arr[e];
        if(abs(a+b)<res){
            res=abs(a+b);
            q=arr[s];
            w=arr[e];
        }
        //더한게 음수이면 바운더리를 왼쪽에서 좁히고
        if(a+b<0)
            s++;
        //양수이면 오른쪽에서 좁히기
        else{
            e--;
        }
    }
    cout<<q<<" "<<w;
    return 0;
}
