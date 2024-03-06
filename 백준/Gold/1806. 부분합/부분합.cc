#include <algorithm>
#include <iostream>
#include <vector>

#define INF 2147483647

using namespace std;

int main() {
	int n, s;
	vector<int>arr;
	int num, sum = 0;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	int en = 0, len = INF;
	for (int st = 0; st < n; st++) {
		while (sum < s && en < n) {
			sum += arr[en];
			en++;
		}
		if (sum >= s) {
			len = min(len, en - st);
		}
		sum -= arr[st];
		
	}
	if (len == INF)cout << 0;
	else cout << len;

	return 0;
}