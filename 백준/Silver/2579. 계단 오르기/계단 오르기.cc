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
	int arr[301];
	int dp[301];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//.....oxoo  -> dp[n] = dp[n-3] + arr[n-1] + arr[n]
	//......oxo  -> dp[n] = dp[n-2] + arr[n]
	// 위 둘 중에 max값 구하면 됨
	// dp[n] = max(dp[n-3] + array[n-1] + array[n], dp[n-2] + array[n])
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1]);
	}
	cout << dp[n - 1];


}