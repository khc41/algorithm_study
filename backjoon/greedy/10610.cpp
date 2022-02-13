#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool divide(vector<int>& v, string n) {
	long long sum = 0;
	bool zero = false;
	for (int i = 0; i < n.size(); i++) {
		int num = n[i] - '0';
		if (num == 0)
			zero = true;
		sum += num;
		v.push_back(num);
	}
	if (sum % 3 == 0 && zero) return true;
	else return false;
}

int main() {
	string n;
	int i;
	cin >> n;
	vector<int> v, t;
	if (divide(v, n)) {
		sort(v.rbegin(), v.rend());
		for (i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	else {
		cout << "-1";
		return 0;
	}
}