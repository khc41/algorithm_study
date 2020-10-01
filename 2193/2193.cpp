#include <iostream>
#include <vector>
using namespace std;

int main() {
	int i, n;
	cin >> n;
	long long *dp = new long long[n];
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i < n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[n-1];
}