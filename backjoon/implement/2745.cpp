#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string n;
	int b, i, mul, sum = 0;
	cin >> n >> b;
	for (i = 0; i < n.size(); i++) {
		if (n[i] <= '9') sum += pow(b, n.size() - 1 - i) * (n[i] - '0');
		else {
			sum += pow(b, n.size() - 1 - i) * (n[i] + 10 - 'A');
		}
	}
	cout << sum;
}