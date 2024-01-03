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

int main() {

	string s;
	cin >> s;
	int size = s.size();
	vector<char> str(size);
	for (int i = 0; i < size; i++) {
		str[i] = s[size - i - 1];
	}
	int cnt = 1;
	for (int i = 0; i < size; i++) {
		if (s[i] != str[i]) cnt = 0;
	}
	cout << cnt;



	return 0;
}
