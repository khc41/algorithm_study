#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, in;
vector<int> have;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int i;
	int high = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> in;
		have.push_back(in);
		high = max(high, in);
	}
	sort(have.begin(), have.end());
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> in;
		auto l = lower_bound(have.begin(), have.end(), in);
		auto h = upper_bound(have.begin(), have.end(), in);
		cout << h - l << " ";
	}
}