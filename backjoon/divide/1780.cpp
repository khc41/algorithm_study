#include <iostream>

using namespace std;

int p[3000][3000];
int result[3] = { 0, };

void check(int x, int y, int n) {
	int a = 0, b = 0, c = 0;
	for (int i = y; i < n + y; i++) {
		for (int j = x; j < n + x; j++) {
			if (p[i][j] == -1) a++;
			else if (p[i][j] == 0) b++;
			else c++;
		}
	}
	if (!a && !b) result[2]++;
	else if (!b && !c) result[0]++;
	else if (!c && !a) result[1]++;
	else {
		for (int i = y; i < n + y; i+= n/3) {
			for (int j = x; j < n + x; j+= n/3) {
				check(j, i, n / 3);
			}
		}
	}
}

int main() {
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> p[i][j];
	check(0, 0, n);
	for (i = 0; i < 3; i++)
		cout << result[i] << "\n";
}