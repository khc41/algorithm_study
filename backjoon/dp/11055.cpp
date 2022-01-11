#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int in[1001] = { 0, };
	int dp[1001] = { 0, };
	for (i = 1; i <= n; i++)
		cin >> in[i];
	for (i = 1; i <= n; i++) {
		for (j = 0; j < i; j++) {
			if (in[i] > in[j]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += in[i];
	}
	int ans = 0;
	for (i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}