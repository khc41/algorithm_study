#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, b, i, mod;
	cin >> n >> b;
	vector<char> v;
	while (n >= b) {
		mod = n % b;
		n /= b;
		if (mod <= 9) v.push_back(mod + 48);
		else {
			v.push_back(mod + 55);
		}
	}
	if (n <= 9) v.push_back(n + 48);
	else {
		v.push_back(n + 55);
	}
	reverse(v.begin(), v.end());
	for (i = 0; i < v.size(); i++)
		cout << v[i];
}