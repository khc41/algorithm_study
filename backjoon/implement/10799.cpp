#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s;
	vector<int> v;
	int i, j, res = 0;
	cin >> s;
	v.push_back(0);
	for (i = 1; i < s.size(); i++) {
		if (s[i] == '(') {
			v.push_back(0);
		}
		else {
			if (s[i - 1] == '(') {
				v.pop_back();
				for (j = 0; j < v.size(); j++) {
					v[j] += 1;
				}
			}
			else {
				res += v[v.size() - 1] + 1;
				v.pop_back();
			}
		}
	}
	cout << res;
}