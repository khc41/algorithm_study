#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> broken;

int cal[500001];

int check(string n) {
	for (int i = 0; i < n.size(); i++) {
		for (int j = 0; j < broken.size(); j++) {
			if (n[i] - '0' == broken[j])
				return 0;
		}
	}
	return 1;
}

int main() {
	int n, m, in, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> in;
		broken.push_back(in);
	}

	int mini = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		if (check(to_string(i))) {
			int tmp = abs(n - i) + to_string(i).size();
			mini = min(mini, tmp);
		}
	}

	cout << mini;
}