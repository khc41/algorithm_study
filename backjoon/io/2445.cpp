#include <iostream>

using namespace std;

int main() {
	int n, i, j, k, l;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++)
			cout << "*";
		for (k = 2 * n - 1; k >= 2*i ; k--)
			cout << " ";
		for (l = 1; l <= i; l++)
			cout << "*";
		cout << endl;
	}
	for (i = n-1; i >= 1; i--) {
		for (j = i; j >= 1; j--)
			cout << "*";
		for (k = 2 * i; k <= 2 * n - 1; k++)
			cout << " ";
		for (l = i; l >= 1; l--)
			cout << "*";
		cout << endl;
	}
}
