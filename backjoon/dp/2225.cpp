#include <iostream>

using namespace std;

int main() {
	int n, k, i, j, l;
	cin >> n >> k;
	int dp[201][201] = { 0, };
	for (i = 0; i <= n; i++)
		dp[1][i] = 1;
	for (i = 2; i <= k; i++) {
		for (j = 0; j <= n; j++) {
			for (l = 0; l <= j; l++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][l]) % 1000000000;
			}
		}
	}
	cout << dp[k][n];
}