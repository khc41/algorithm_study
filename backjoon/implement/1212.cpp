#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	int i, j;
	for (i = 0; i < s.size(); i++) {
		vector<int> v;
		int num = s[i] - '0';
		int cnt = 0;
		while (num > 1) {
			v.push_back(num % 2);
			num /= 2;
			cnt++;
		}
		v.push_back(num);
		if (i != 0) {
			for (j = 0; j < 2 - cnt; j++) {
				cout << "0";
			}
		}
		for (j = v.size() - 1; j >= 0; j--)
			cout << v[j];
	}
}