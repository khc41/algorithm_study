#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, i, j = 0;
	cin >> n;
	long long int sum = 0;
	long dp[101][10] = { 0, };
	for (i = 1; i < 10; i++)
		dp[1][i] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]);
			dp[i][j] %= 1000000000;
		}
	}
	for (i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) % 1000000000;
	cout << sum;
}