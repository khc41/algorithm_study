#include <iostream>

using namespace std;

long long divTwo(long long n) {
	long long cnt = 0;
	for (long long i = 2; i <= n; i *= 2) {
		cnt += n / i;
	}
	return cnt;
}

long long divFive(long long n) {
	long long cnt = 0;
	for (long long i = 5; i <= n; i *= 5) {
		cnt += n / i;
	}
	return cnt;
}

int main() {
	long long n, m, i, ans = 0;
	long long cnt[2];
	cin >> n >> m;
	cnt[0] = divTwo(n) - divTwo(n - m) - divTwo(m);
	cnt[1] = divFive(n) - divFive(n - m) - divFive(m);
	cout << min(cnt[0], cnt[1]);
}