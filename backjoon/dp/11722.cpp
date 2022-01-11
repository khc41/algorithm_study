#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int in[1001] = { 0, };
	int dp[1001] = { 0, };
	for (i = 1; i <= n; i++) cin >> in[i];
	for (i = 1; i <= n; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (in[i] < in[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
}