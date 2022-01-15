#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, i, j;
	string in;
	vector<char> v;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> in;
		v.clear();
		for (j = 0; j < in.size(); j++) {
			if (in[j] == '(') v.push_back(in[j]);
			else {
				if (v.size() == 0) {
					j -= 1;
					break;
				}
				else v.pop_back();
			}
		}
		if (v.size() == 0 && j == in.size()) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
}