#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	char in, w;
	int m, i;
	cin >> s;
	list<char> l(s.begin(), s.end());
	auto cur = l.end();
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> in;
		if (in == 'L') {
			if (cur != l.begin())
				cur--;
		}
		else if (in == 'D') {
			if (cur != l.end())
				cur++;
		}
		else if (in == 'B') {
			if (cur != l.begin())
				cur = l.erase(--cur);
		}
		else if (in == 'P') {
			cin >> w;
			cur = l.insert(cur, w);
			cur++;
		}
	}
	for (auto it = l.begin(); it != l.end(); it++) {
		cout << *it;
	}
}