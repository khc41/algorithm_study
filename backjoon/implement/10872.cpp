#include <iostream>

using namespace std;

int main() {
	int n, i, fac = 1;
	cin >> n;
	for (i = 1; i <= n; i++) {
		fac *= i;
	}
	cout << fac;
}