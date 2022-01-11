#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int in[301];
	int dp[301] = { 0, };
	for (i = 1; i <= n; i++) cin >> in[i];
	dp[1] = in[1]; dp[2] = in[1] + in[2];
	for (i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + in[i], in[i - 1] + in[i] + dp[i-3]);
	}
	cout << dp[n];
}