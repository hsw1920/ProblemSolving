#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c;
long long int pow(int b) {
	if (b == 0) {
		return 1;
	}
	long long int tmp;
	

	tmp=pow(b / 2);
	tmp = tmp * tmp % c;
	if (b % 2)
		return a * tmp % c;
	return tmp;
	
	
}

int main() {
	long long int num = 1;
	cin >> a >> b >> c;
	long long int k=pow(b);
	cout << k;
	return 0;
}