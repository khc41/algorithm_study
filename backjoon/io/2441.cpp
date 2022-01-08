#include <iostream>

using namespace std;

int main() {
	int n, i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++)
			cout << " ";
		for (k = n; k >= i; k--)
			cout << "*";
		cout << endl;
	}
}