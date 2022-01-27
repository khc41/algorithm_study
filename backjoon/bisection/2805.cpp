#include <iostream>
#include <cmath>
using namespace std;

long long n, m;
long long* tree;

bool cut(long long h) {
	long long length = 0;
	for (int i = 0; i < n; i++) {
		if(tree[i] >= h)
			length += tree[i]-h;
	}
	cout << h << " " << length << endl;
	if (length >= m) return true;
	else return false;
}

int main() {
	int i;
	cin >> n >> m;
	long long low = 1;
	long long high = 0;
	long long result = 0;
	tree = new long long[n];
	for (i = 0; i < n; i++) {
		cin >> tree[i];
		high = max(tree[i], high);
	}
	while (low <= high) {
		long long mid = (low + high) / 2;
		cout << low << " " << high << endl;
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