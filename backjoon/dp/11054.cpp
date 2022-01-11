#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int a[1001];
	int up[1001] = { 0, };
	int dn[1001] = { 0, };
	for (i = 1; i <= n; i++) cin >> a[i];
	for (i = 1; i <= n; i++) {
		up[i] = 1;
		for (j = 0; j < i; j++) {
			if (a[i] > a[j]) up[i] = max(up[j] + 1, up[i]);
		}
	}
	for (i = n; i >= 1; i--) {
		for (j = n; j > i; j--) {
			if (a[i] > a[j]) dn[i] = max(dn[j] + 1, dn[i]);
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++) ans = max(ans, up[i] + dn[i]);
	cout << ans;
}