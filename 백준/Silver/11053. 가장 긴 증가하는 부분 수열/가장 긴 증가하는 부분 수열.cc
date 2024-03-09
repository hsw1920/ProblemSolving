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
	int dp[1000];
	int arr[1000];
	int sum = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;

		for (int j = 0; j < i; j++) {

			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
		sum = max(sum, dp[i]);
	}
	cout << sum;
}