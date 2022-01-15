#include <iostream>
#include <string>
using namespace std;

int main() {
	int i;
	char c[150];
	string s;
	for (i = 'a'; i <= 'z'; i++) {
		if ((i + 13) <= 'z')
			c[i] = char(i + 13);
		else
			c[i] = char(i + 13 - 26);
	}
	for (i = 'A'; i <= 'Z'; i++) {
		if ((i + 13) <= 'Z')
			c[i] = char(i + 13);
		else
			c[i] = char(i + 13 - 26);
	}
	getline(cin, s);
	for (i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'z')
			s[i] = c[s[i]];
		else
			continue;
	}
	cout << s;
}