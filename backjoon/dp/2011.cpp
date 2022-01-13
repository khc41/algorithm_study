#include <iostream>
#include <string>

#define mod 1000000
using namespace std;

int main() {
	int i;
	string n;
	cin >> n;
	long long int dp[5001] = { 0, };
	if (n[0] == '0') {
		cout << '0'; return 0;
	} 
	dp[0] = 1; dp[1] = 1;
	for (i = 2; i <= n.size(); i++) {
		int sum = (n[i - 1] - '0') + (n[i - 2] - '0') * 10;
		if(n[i-1] > '0') dp[i] = dp[i-1] % mod;
		if (sum <= 26 && sum >= 10) {
			dp[i] = (dp[i - 2] + dp[i]) % mod;
		}
	}
	cout << dp[n.size()];
}