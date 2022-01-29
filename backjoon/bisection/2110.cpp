#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, c;
long long result = 0;
vector<long long> x;

bool install(long long n) {
	int cnt = 1;
	long long pre = x[0];
	long long dis = 987654321;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] - pre >= n) {
			dis = min(dis, x[i] - pre);
			cnt++;
			pre = x[i];
		}
	}
	if (cnt >= c) {
		result = dis;
		return true;
	}
	else return false;
}

int main() {
	int i;
	long long in;
	long long low = 1;
	long long high = 0;
	long long mid;
	cin >> n >> c;
	for (i = 0; i < n; i++) {
		cin >> in;
		x.push_back(in);
		high = max(high, in);
	}
	sort(x.begin(), x.end());
	while (low <= high) {
		mid = (low + high) / 2;
		if (install(mid)) {
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result;
}