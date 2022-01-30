#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, in;
vector<int> have;

int comp(int num) {
	if (have[num] >= in) return true;
	else return false;
}

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
	for(i = 0; i < m; i++) {
		int l = 0;
		int h = have.size() - 1;
		cin >> in;
		int mid = 0;
		while (l <= h) {
			mid = (l + h) / 2;
			if (have[mid] == in) {
				cout << "1 ";
				break;
			}
			else if (have[mid] < in) l = mid + 1;
			else h = mid - 1;
		}
		if (have[mid] != in) cout << "0 ";
	}
}