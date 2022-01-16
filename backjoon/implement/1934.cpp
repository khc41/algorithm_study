#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int t, tc, j, a, b;
	cin >> t;
	for (tc = 0; tc < t; tc++) {
		cin >> a >> b;
		cout << lcm(a, b) << endl;
	}
}