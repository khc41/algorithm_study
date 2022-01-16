#include <iostream>

using namespace std;

int main() {
	int a, b, i;
	cin >> a >> b;
	int x = 1, y = 1;
	int n = a > b ? b : a;
	for (i = n; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			a /= i;
			b /= i;
			x *= i;
			y *= i;
		}
	}
	cout << x << endl;
	cout << y * a * b << endl;
}