#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int dp[100001] = { 0, };
	for (i = 1; i <= n; i++) {
		dp[i] = i;
		for (j = 1; j * j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1)
				dp[i] = dp[i - j * j] + 1;
		}
	}
	cout << dp[n];
}