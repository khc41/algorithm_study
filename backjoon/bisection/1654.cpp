#include <iostream>
#include <cmath>
using namespace std; 

int n, k;
long long* line;

bool cut(int mid) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += line[i] / mid;
	}
	if (cnt >= n) return true;
	else return false;
}

int main() {
	int i;
	long long low = 1; 
	long long high = 0;
	long long result = 0;
	cin >> k >> n;
	line = new long long[k];
	for (i = 0; i < k; i++) {
		cin >> line[i];
		high = max(high, line[i]);
	}
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (cut(mid)) {
			if (result < mid) result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result;
}