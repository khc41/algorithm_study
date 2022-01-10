#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n, tc, i, j, k;
	cin >> t;
	int dp[2][100001];
	int input[2][100001];
	for (tc = 0; tc < t; tc++) {
		cin >> n;
		for (i = 0; i < 2; i++)
			for (j = 0; j < n; j++)
				cin >> input[i][j];
		dp[0][0] = input[0][0]; 
		dp[1][0] = input[1][0];
		dp[0][1] = input[1][0] + input[0][1]; 
		dp[1][1] = input[0][0] + input[1][1];
		for (i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + input[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + input[1][i];
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}
}