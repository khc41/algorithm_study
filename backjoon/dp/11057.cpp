#include <iostream>

using namespace std;

int main() {
	int n, i, j, k;
	cin >> n;
	long dp[1001][10] = {0,};
	long result = 0;
	for (i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k <= j; k++)
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
		}
	}
	for (i = 0; i < 10; i++)
		result = (result + dp[n][i]) % 10007;
	cout << result;
}