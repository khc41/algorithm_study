#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	long long r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	long long a, b, i;
	cin >> a >> b;
	long long n = gcd(a, b);
	while (n--) cout << "1";
}