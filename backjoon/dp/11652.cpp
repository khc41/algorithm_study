#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, i;
	int cnt = 1;
	int max = 1;
	long long a[100001] = { 0, };
	long long maxValue;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	maxValue = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] == a[i - 1])
			cnt++;
		else cnt = 1;

		if (cnt > max) {
			max = cnt;
			maxValue = a[i];
		}
	}
	cout << maxValue;
}