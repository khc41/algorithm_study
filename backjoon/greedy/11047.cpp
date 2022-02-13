#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k, i, result = 0;
	cin >> n >> k;
	vector<int> v(n);
	for (i = 0; i < n; i++) {
		cin >> v[i];
	}
	while (k > 0) {
		for (i = n - 1; i >= 0; i--) {
			while (k - v[i] >= 0) {
				k -= v[i];
				result++;
			}
		}
	}
	cout << result;
}