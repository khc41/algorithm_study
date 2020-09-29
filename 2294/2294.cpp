#include <iostream>

using namespace std;

int dp[10001];

int main() {
	int i,j, n, k;
	cin >> n >> k;
	int* coin = new int[n];
	for (i = 0; i < n; i++)
		cin >> coin[i];
	for (i = 1; i < k + 1; i++)
		dp[i] = 100001;
	
	for (i = 1; i < k + 1; i++) {
		for (j = 0; j < n; j++) {
			if (coin[j] == i) {
				dp[i] = 1;
			}
			if (i - coin[j] > 0) 
				dp[i] = min(dp[i - coin[j]] + 1, dp[i]);
		}
	}
	if (dp[k] == 100001)
		cout << -1;
	else
		cout << dp[k];
}