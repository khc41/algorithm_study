#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> dp(11);
	vector<int> in(t);
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	
	for (int i = 0; i < t; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < t; i++) {
		cout << dp[in[i]] << endl;
	}
}