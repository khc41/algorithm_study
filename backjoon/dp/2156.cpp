#include <iostream>

using namespace std;

int main() {
	int n, i;
	int input[10001] = { 0, };
	int dp[10001] = { 0, };
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> input[i];
	dp[1] = input[1];
	dp[2] = dp[1] + input[2];
	for (i = 3; i <= n; i++) {
		dp[i] = max(input[i] + input[i - 1] + dp[i - 3], max(input[i] + dp[i - 2], dp[i - 1]));
	}
	cout << dp[n];
}