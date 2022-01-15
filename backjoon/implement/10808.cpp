#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int i;
	int alpha[150] = { 0, };
	for (i = 0; i < s.size(); i++) {
		alpha[s[i]] ++;
	}
	for (i = 'a'; i <= 'z'; i++) {
		printf("%d ", alpha[i]);
	}
}