#include <iostream>

using namespace std;

int main() {
	int n, i;
	cin >> n;
	long long int dp[91][2] = { 0, };
	long long int result = 0;
	dp[1][1] = 1;
	for (i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	for (i = 0; i <= 1; i++)
		result += dp[n][i];
	cout << result;
}