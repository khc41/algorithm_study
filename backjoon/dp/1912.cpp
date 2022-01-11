#include <iostream>

using namespace std;

int main() {
	int n, i;
	cin >> n;
	int in[100001];
	int dp[100001] = { 0, };
	for (i = 1; i <= n; i++) cin >> in[i];
	for (i = 1; i <= n; i++) {
		dp[i] = max(in[i], dp[i - 1] + in[i]);
	}
	int ans = -1001;
	for (i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout <<ans;
}