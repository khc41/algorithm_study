#include <iostream>

using namespace std;

int main() {
	int n, i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = n; j > i; j--)
			cout << " ";
		for (k = 1; k <= i ; k++)
			cout << "*";
		cout << endl;
	}
	for (i = n-1; i >= 1; i--) {
		for (j = n; j > i; j--)
			cout << " ";
		for (k = i; k >= 1; k--)
			cout << "*";
		cout << endl;
	}
}