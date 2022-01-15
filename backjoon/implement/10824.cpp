#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, c, d;
	long long x, y;
	cin >> a >> b >> c >> d;
	x = stoll(a + b);
	y = stoll(c + d);

	printf("%lld", x + y);
}