#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int i;
	string s;
	int a[150];
	cin >> s;
	fill_n(a, 150, -1);
	for (i = 0; i < s.size(); i++) {
		if (a[s[i]] == -1)
			a[s[i]] = i;
	}
	for (i = 'a'; i <= 'z'; i++)
		printf("%d ", a[i]);
}