#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int dp[31] = { 0, };
	dp[0] = 1;
	dp[2] = 3;
	for (i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = 3 * dp[i - 2];
			for (j = i - 4; j >= 0; j-=2) {
				dp[i] += dp[j] * 2;
			}
		}
	}
	cout << dp[n];
}