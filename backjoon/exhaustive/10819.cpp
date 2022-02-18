#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

long long cal(vector<int> a) {
	long long sum = 0;
	for (int i = 0; i < a.size() - 1; i++) {
		sum += abs(a[i] - a[i + 1]);
	}
	return sum;
}

int main() {
	int n, in;
	long long result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		a.push_back(in);
	}
	sort(a.begin(), a.end());

	do {
		vector<int> n;
		for (auto it = a.begin(); it != a.end(); ++it) {
			n.push_back(*it);
		}
		result = max(result, cal(n));
	} while (next_permutation(a.begin(), a.end()));

	cout << result;
}