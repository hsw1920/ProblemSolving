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


int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cout.tie(0); cout.sync_with_stdio(0);
    int n, m; 
    cin >> n >> m;
    map<string, int> dogam_for_str; 
    vector<string> dogam_for_index(n + 1);
    for (int i = 1; i <= n; i++) { 
        string str; 
        cin >> str; 
        dogam_for_index[i] = str;
        dogam_for_str[str] = i; 
    } 
    for (int i = 1; i <= m; i++) {

        string temp; 
        cin >> temp; // 숫자인 경우 바로 인덱스로 접근 
        if(atoi(temp.c_str()) != 0){
            cout << dogam_for_index[atoi(temp.c_str())] << '\n'; 
        }
        else{
            // 문자인 경우 
            cout << dogam_for_str[temp] << '\n'; 
        } 
    }

    return 0;
}