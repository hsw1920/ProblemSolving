#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	int arr[3][1001];
	int dp[3][1001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[0][i];
		cin >> arr[1][i];
		cin >> arr[2][i];
	}
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[2][0] = arr[2][0];
	for (int i = 1; i < n; i++) {
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + arr[0][i];// r
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + arr[1][i];// g
		dp[2][i] = min(dp[1][i - 1], dp[0][i - 1]) + arr[2][i];// b
	}
	cout << min({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] });

	return 0;
}