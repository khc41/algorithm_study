#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, p = 0, m = 0, z = 0, p_i, m_i, z_i;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] < 0) m++;
		else if (v[i] > 0) p++;
		else z++;
	}

	sort(v.rbegin(), v.rend());
	long long sum = 0;

	p_i = 0; z_i = p; m_i = p + z;

	for (int i = 0; i < z_i; i++) {
		if (i != n - 1 && v[i + 1] > 0) {
			sum += max(v[i] * v[i + 1], v[i] + v[i + 1]);
			i++;
		}
		else
			sum += v[i];
	}

	for(int i = z_i; i < m_i; i++) {
		if (m % 2 != 0 && m != 0) {
			m--;
			v[i+z] = 0;
		}
	}

	for (int i = n - 1; i > m_i - 1; i--) {
		if (i != m_i) {
			sum += v[i] * v[i - 1];
			i--;
		}
		else
			sum += v[i];
	}

	cout << sum;
}