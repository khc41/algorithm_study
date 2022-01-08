#include <iostream>

using namespace std;

int main() {
	int n, i, j, k, l;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = n; j > i; j--)
			cout << " ";
		if (i == n || i == 1) {
			for (k = 1; k < 2 * i; k++)
				cout << "*";
		}
		else {
			cout << "*";
			for (l = 1; l < 2 * (i-1); l++)
				cout << " ";
			cout << "*";
		}
		cout << endl;
	}
}