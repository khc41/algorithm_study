#include <iostream>

using namespace std;

int main() {
	int n, i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (k = n - 1; k >= i; k--)
			cout << " ";
		for (j = 0; j < 2 * i - 1; j++)
			cout << "*";
		cout << endl;
	}
}