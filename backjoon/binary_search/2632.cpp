#include <iostream>
#include <map>
using namespace std;

int a[2001];
int b[2001];
int m, n, p;
int ret = 0;
map<int, int> sub_sum;

int main() {
	cin >> p >> m >> n;
	for (int i = 0; i < m; i++) {
		int in;
		cin >> in;
		a[i] = in; a[m + i] = in;
	}
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		b[i] = in; b[n + i] = in;
	}
	sub_sum[0] = 1;
	for (int i = 0; i < m; i++) {
		int idx = 0;
		int sum = 0;
		int cnt = 0;
		while (idx <= i) {
			sum += a[idx++];
			cnt++;
		}
		idx = 0;
		while (idx < m) {
			if(sum <= p)
				sub_sum[sum] ++;
			if (i == m - 1)
				break;
			sum -= a[idx];
			sum += a[idx + cnt];
			idx++;
		}
	}

	for (int i = 0; i < n; i++) {
		int idx = 0;
		int sum = 0;
		int cnt = 0;
		while (idx <= i) {
			sum += b[idx++];
			cnt++;
		}
		idx = 0;
		while (idx < n) {
			ret += sub_sum[p - sum];
			if (i == n - 1)
				break;
			sum -= b[idx];
			sum += b[idx+ cnt];
			idx++;
		}
	}
	ret += sub_sum[p];
	cout << ret;
}