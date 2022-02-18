#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 987654321

int map[11][11];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	long long result = MAX;
	for (int i = 0; i < n; i++) {
		vector<int> city;
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			city.push_back(j);
		}
		do {
			long long sum = 0;
			vector<int> a;
			a.push_back(i);
			for (auto it = city.begin(); it != city.end(); ++it) {
				a.push_back(*it);
			}
			a.push_back(i);
			for (int i = 0; i < a.size() - 1; i++) {
				if (map[a[i]][a[i + 1]] == 0){
					sum = MAX;
					break;
				}
				sum += map[a[i]][a[i + 1]];
			}
			result = min(result, sum);
		} while (next_permutation(city.begin(), city.end()));
	}
	cout << result;
}