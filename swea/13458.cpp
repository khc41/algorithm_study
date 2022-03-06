#include <iostream>
#include <vector>
using namespace std;

int n, b, c;

int main() {
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> b >> c;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		v[i] -= b;
		ans++;
		if (v[i] > 0) {
			if (v[i] % c == 0)
				ans += v[i] / c;
			else
				ans += (v[i] / c) + 1;
		}
	}
	cout << ans;
}