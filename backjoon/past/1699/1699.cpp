#include <iostream>
#include <vector>
using namespace std;
int dp[100001];
vector<int> num;

int main() {
	int i, j, n;
	cin >> n;
	for (i = 0; i < 100000; i++) {
		dp[i] = 987654321;
	}
	for (i = 1; i * i < 100000; i++) {
		num.push_back(i * i);
	}

	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < num.size(); j++) {
			if (num[j] > i)
				break;
			if (i == num[j]) {
				dp[i] = 1;
				break;
			}
			if (dp[i - num[j]] + 1 < dp[i])
				dp[i] = dp[i - num[j]] + 1;
		}
	}
	cout << dp[n] << endl;
}