#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, i, j;
	vector<int> v;
	cin >> n;
	while (n > 1) {
		for (j = 2; j <= n; j++) {
			if (n % j == 0) {
				v.push_back(j);
				n /= j;
				break;
			}
		}
	}
	sort(v.begin(), v.end());
	for (i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}