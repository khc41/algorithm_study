#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF (1 << 30)

int n, x, y;
vector<pair<int, int>> v;
set<pair<int, int>> s;

int dist(pair<int, int> a, pair<int, int> b) {
	int x = (a.first - b.first) * (a.first - b.first);
	int y = (a.second - b.second) * (a.second - b.second);
	return x + y;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());
	s.insert({ v[0].second, v[0].first });
	s.insert({ v[1].second, v[1].first });
	
	int mini = dist(v[0], v[1]);
	int idx = 0;

	for (int i = 2; i < n; ++i) {
		while (idx < i) {
			int dist = v[i].first - v[idx].first;
			if (dist * dist <= mini) break;
			else {
				s.erase({ v[idx].second, v[idx].first });
				idx++;
			}
		}
		auto start = s.lower_bound({ v[i].second - sqrt(mini), -INF });
		auto end = s.upper_bound({ v[i].second + sqrt(mini), INF });
		for (auto it = start; it != end; it++) {
			mini = min(mini, dist({ it->second, it->first }, v[i]));
		}
		s.insert({ v[i].second, v[i].first });
	}
	cout << mini << "\n";
}