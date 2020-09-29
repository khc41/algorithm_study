#include <iostream>
#include <algorithm>

int st[2][100001];
int dp[2][100001];

using namespace std;

int main() {
	int test_case, in, i, j;
	cin >> in;
	for (test_case = 0; test_case < in; test_case++) {
		int n, tmp;
		cin >> n;

		for (i = 0; i < 2; i++)
			for (j = 0; j < n; j++) 
				cin >> st[i][j];

		dp[0][0] = st[0][0];
		dp[1][0] = st[1][0];
		dp[0][1] = st[1][0] + st[0][1];
		dp[1][1] = st[0][0] + st[1][1];
		for (i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + st[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + st[1][i];
		}
		cout << max(dp[0][n-1], dp[1][n-1]) << endl;
	}
}