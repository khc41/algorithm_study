#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, i, k, in;
	cin >> n >> k;
	vector<int> a;
	for (i = 0; i < n; i++) {
		cin >> in;
		a.push_back(in);
	}
	sort(a.begin(), a.end());
	printf("%d", a[k - 1]);
}