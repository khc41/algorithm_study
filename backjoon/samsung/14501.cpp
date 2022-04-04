#include <iostream>

using namespace std;

int n;
int t[16];
int p[16];
int ans = 0;

void solve(int day, int sum) {
	if (day + t[day] > n || day >= n) {
		ans = max(ans, sum);
		if (day < n) solve(day + 1, sum);
		return;
	}

	solve(day + t[day], sum + p[day]);
	solve(day + 1, sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		cin >> p[i];
	}
	solve(0, 0);
	cout << ans;
}