#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int m, n, i, j;
	vector<int> v;
	cin >> m >> n;
	for (i = m; i <= n; i++) {
		int cnt = 0;
		for (j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				cnt++;
				break;
			}
		}
		if (cnt == 0 && i >= 2) {
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	for (i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

}