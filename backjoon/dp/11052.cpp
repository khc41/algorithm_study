#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int in[10001];
	int dp[10001] = { 0, };
	for (i = 1; i <= n; i++) cin >> in[i];
	dp[1] = in[1];
	for (i = 2; i <= n; i++) {
		dp[i] = in[i];
		for (j = 1; j < i; j++) {
			dp[i] = max(dp[j] + in[i - j], dp[i]);
		}
	}
	cout << dp[n];
}