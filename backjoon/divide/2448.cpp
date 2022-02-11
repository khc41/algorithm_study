#include <iostream>

using namespace std;

char arr[3073][6144];

void triangle(int n, int i, int j) {
	if (n == 3) {
		arr[j][i] = '*';
		arr[j + 1][i + 1] = '*';
		arr[j + 1][i - 1] = '*';
		for (int k = 0; k < 5; k++) {
			arr[j + 2][i - 2 + k] = '*';
		}
		return;
	}
	triangle(n / 2, i, j);
	triangle(n / 2, i - n / 2, j + n / 2);
	triangle(n / 2, i + n / 2, j + n / 2);
}


int main() {
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n - 1; j++) {
			arr[i][j] = ' ';
		}
	}
	triangle(n, n - 1, 0);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}