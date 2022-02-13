#include <iostream>

using namespace std;

int main() {
	int n, m, k, result = 0;
	cin >> n >> m >> k;
	while (n >= 0 && m >= 0) {
		if (n + m < k) {
			result--;
			break;
		}
		if (n - 2 < 0 || m - 1 < 0)
			break;
		n -= 2;
		m -= 1;
		result++;
	}
	cout << result;
}