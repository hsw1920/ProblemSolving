#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include <queue>
#include <map>
using namespace std; // cin,cout 편하게 사용 라이브러리

// memset(maps, 0, sizeof(maps));
// memset 사용시 #include <cstring> 헤더파일 필요함
// fill(v.begin(), v.end(), 1);
int n;
int t[16];
int p[16];
int pay = 0;
void check(int i, int sum) {

    if (i<=n) { 
        if (i != n) {
            check(i + 1, sum);
        }
        if (i + (t[i] - 1) <= n) {
            sum += p[i];
            pay = max(pay, sum);
            check(i + t[i], sum);
        }
    }
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cout.tie(0); cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        check(i, 0);
    }
    cout << pay;

    return 0;
}