#include <iostream>

using namespace std;

int q[65][65];

void quardTree(int x, int y, int n) {
	if (n == 1)
		cout << q[y][x];
	else {
		int cnt = 0;
		for (int i = y; i < y + n; i++)
			for (int j = x; j < x + n; j++) {
				cnt += q[i][j];
			}
		if (cnt == 0) cout << "0";
		else if (cnt == n * n) cout << "1";
		else {
			cout << "(";
			for (int i = 0; i < n; i+= n/2)
				for (int j = 0; j < n; j+= n/2)
					quardTree(x + j, y + i, n/2);
			cout << ")";
		}
	}
	
}

int main() {
	int N, i, j;
	string in;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> in;
		for (j = 0; j < N; j++)
			q[i][j] = in[j] - '0';
	}
	quardTree(0, 0, N);
}