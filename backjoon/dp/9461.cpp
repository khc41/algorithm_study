#include <iostream>

using namespace std;

int main() {
	int t, n, i, j;
	cin >> t;
	long long int dp[101] = { 0, };
	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	dp[4] = 2; dp[5] = 2;
	for (i = 0; i < t; i++) {
		cin >> n;
		for (j = 6; j <= n; j++) {
			dp[j] = dp[j - 1] + dp[j - 5];
		}
		cout << dp[n] << endl;
	}
}