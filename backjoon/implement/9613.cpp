#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	long long r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int t, tc, n, i, j;
	cin >> t;
	for (tc = 0; tc < t; tc++) {
		cin >> n;
		long long num[101];
		long long sum = 0;
		for (i = 1; i <= n; i++) {
			cin >> num[i];
		}
		for (i = 1; i <= n; i++) {
			for (j = i + 1; j <= n; j++) {
				sum += gcd(num[i], num[j]);
			}
		}
		cout << sum << endl;
	}
}