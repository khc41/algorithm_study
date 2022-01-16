#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, k, i;
	cin >> n >> k;
	vector<int>a, ans;
	for (i = 0; i < n; i++) a.push_back(i + 1);
	int cur = -1;
	while (a.size() > 0) {
		cur += k;
		while (cur >= a.size()) {
			cur = cur - a.size();
		}
		ans.push_back(a[cur]);
		a.erase(a.begin() + cur--);
	}
	cout << "<";
	for (auto i = ans.begin(); i < ans.end(); i++) {
		cout << *i;
		if (i != ans.end() - 1)
			cout << ", ";
	}
	cout << ">";
}