#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	vector<int> v;
	int i;
	cin >> s;
	for (i = s.size() - 1; i > 1; i-=3) {
		int sum = 0;
		sum += s[i] - '0';
		sum += (s[i - 1] - '0') * 2;
		sum += (s[i - 2] - '0') * 4;
		v.push_back(sum);
	}
	switch (s.size() % 3) {
	case 1: 
		v.push_back(s[0] - '0');
		break;
	case 2: 
		v.push_back(s[1] - '0' + (s[0] - '0') * 2);
		break;
	}
	for (i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}