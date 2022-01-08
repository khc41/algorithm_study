#include <iostream>
#include <vector>
using namespace std;

int calPaint(vector<vector<char>>& board, int i, int j) {
	int x, y, cnt;
	cnt = 0;
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 8; x++) {
			if ((x + y) % 2 == 0) {
				if (board[i + y][j + x] != board[i][j])
					cnt++;
			}
			else{
				if (board[i + y][j + x] == board[i][j])
					cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int m, n, i, j, min, res;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m, ' '));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	min = 987654321;
	for (i = 0; i < n - 7; i++) {
		for (j = 0; j < m - 7; j++) {
			res = calPaint(board, i, j);
			res = res > 64 - res ? 64 - res : res;
			if (res < min)
				min = res;
		}
	}
	cout << min;
}