#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	int i;
	cin >> s;
	string a[1001]; 
	for (i = 0; i < s.size(); i++) {
		a[i] = s.substr(i);
	}
	sort(a, a + s.size());
	for (i = 0; i < s.size(); i++) {
		printf("%s\n", a[i].c_str());
	}
}