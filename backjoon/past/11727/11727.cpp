#include <iostream>

using namespace std;

int main() {
	int n, i;
	cin >> n;
	int* dp = new int[n];
	dp[0] = 1;
	dp[1] = 3;
	for (i = 2; i < n; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}
	cout << dp[n - 1];
}