#include <iostream>

using namespace std;

int main() {
	int n, i, j, ans = 0;
	int num[101] = { 0, };
	cin >> n;
	for (i = 0; i < n; i++) cin >> num[i];
	for (i = 0; i < n; i++) {
		int cnt = 0;
		for (j = 1; j <= num[i]; j++) {
			if (num[i] % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2)
			ans++;
	}
	cout << ans;
}