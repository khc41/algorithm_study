#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> sum1;
vector<long long> sum2;
int n;
long long a[4001];
long long b[4001];
long long c[4001];
long long d[4001];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; cin >> b[i];
		cin >> c[i]; cin >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum1.push_back(a[i] + b[j]);
		}
	}
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum2.push_back(c[i] + d[j]);
		}
	}

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	int s = 0; int e = sum2.size() - 1;
	while (s < sum1.size() && e >= 0) {
		long long sum = sum1[s] + sum2[e];
		if (sum == 0) {
			long long u = upper_bound(sum1.begin(), sum1.end(), sum1[s]) - sum1.begin();
			long long l = lower_bound(sum2.begin(), sum2.end(), sum2[e]) - sum2.begin();
			ret += (u - s) * (e - l + 1);
			s = u;
			e = l - 1;
		}
		else if (sum > 0) e--;
		else s++;
	}


	cout << ret;
}