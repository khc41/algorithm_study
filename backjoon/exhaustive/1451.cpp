#include <iostream>
#include <vector>

using namespace std;

long long map[51][51];

long long sum(int sx, int sy, int ex, int ey) {
	long long num = 0;
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			num += map[i][j];
		}
	}
	return num;
}

int main() {
	int n, m;
	long long result = 0;
	string in;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> in;
		for (int j = 0; j < m; j++) {
			map[i][j] = in[j] - '0';
		}
	}
			
	// case: 1
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			long long a = sum(0, 0, m - 1, i);
			long long b = sum(0, i + 1, m - 1, j);
			long long c = sum(0, j + 1, m - 1, n - 1);
			if (result < a * b * c) result = a * b * c;
		}
	}

	// case: 2
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			long long a = sum(0, 0, i, n - 1);
			long long b = sum(i + 1, 0, j, n - 1);
			long long c = sum(j + 1, 0, m - 1, n - 1);
			if (result < a * b * c) result = a * b * c;
		}
	}

	// case: 3
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			long long a = sum(0, 0, i, n - 1);
			long long b = sum(i + 1, 0, m - 1, j);
			long long c = sum(i + 1, j + 1, m - 1, n - 1);
			if (result < a * b * c) result = a * b * c;
		}
	}

	// case: 4
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			long long a = sum(i + 1, 0, m - 1, n - 1);
			long long b = sum(0, 0, i, j);
			long long c = sum(0, j + 1, i, n - 1);
			if (result < a * b * c) result = a * b * c;
		}
	}

	// case: 5
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			long long a = sum(0, 0, m, j);
			long long b = sum(0, j + 1, i, n);
			long long c = sum(i + 1, j + 1, m, n);
			if (result < a * b * c) result = a * b * c;
		}
	}

	// case: 6
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			long long a = sum(0, j + 1, m, n);
			long long b = sum(0, 0, i, j);
			long long c = sum(i + 1, 0, m, j);
			if (result < a * b * c) result = a * b * c;
		}
	}

	cout << result;
}