#include <iostream>

using namespace std;

int n, m;
int ans = 0;

int p[501][501];

void solve(int x, int y) {
	int sum;
	if (x + 3 < m) {
		sum = 0;
		for (int i = 0; i < 4; i++)
			sum += p[y][x + i];
		ans = max(ans, sum);
	}
	if (y + 3 < n) {
		sum = 0;
		for (int i = 0; i < 4; i++)
			sum += p[y + i][x];
		ans = max(ans, sum);
	}
	if (x + 1 < m && y + 1 < n) {
		sum = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				sum += p[y + i][x + j];
		ans = max(ans, sum);
	}
	if (x + 1 < m && y + 2 < n) {
		sum = 0;
		for (int i = 0; i < 3; i++)
			sum += p[y + i][x];
		sum += max(p[y][x + 1], p[y + 2][x + 1]);
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 3; i++)
			sum += p[y + i][x + 1];
		sum += max(p[y][x], p[y + 2][x]);
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 2; i++)
			sum += p[y + 1][x + i];
		sum += p[y][x] + p[y + 2][x + 1];
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 2; i++)
			sum += p[y + 1][x + i];
		sum += p[y][x + 1] + p[y + 2][x];
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 3; i++)
			sum += p[y + i][x];
		sum += p[y + 1][x + 1];
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 3; i++)
			sum += p[y + i][x + 1];
		sum += p[y + 1][x];
		ans = max(ans, sum);
	}
	if (x + 2 < m && y + 1 < n) {
		sum = 0;
		for (int i = 0; i < 3; i++)
			sum += p[y][x + i];
		sum += max(p[y + 1][x], p[y + 1][x + 2]);
		ans = max(ans, sum);
		
		sum = 0;
		for (int i = 0; i < 3; i++)
			sum += p[y + 1][x + i];
		sum += max(p[y][x], p[y][x + 2]);
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 2; i++)
			sum += p[y + i][x + 1];
		sum += p[y + 1][x] + p[y][x + 2];
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 2; i++)
			sum += p[y + i][x + 1];
		sum += p[y][x] + p[y + 1][x + 2];
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 3; i++)
			sum += p[y][x + i];
		sum += p[y + 1][x + 1];
		ans = max(ans, sum);

		sum = 0;
		for (int i = 0; i < 3; i++)
			sum += p[y + 1][x + i];
		sum += p[y][x + 1];
		ans = max(ans, sum);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> p[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			solve(j, i);
	cout << ans;
}