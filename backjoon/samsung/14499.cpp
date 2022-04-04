#include <iostream>

using namespace std;

int n, m, x, y, k;

int map[21][21];
int dice[6];

int dir[4][2] = { {1,0}, {-1,0}, {0,-1}, {0,1} };

void move(int direction) {
	int cp[6];
	for (int i = 0; i < 6; i++) cp[i] = dice[i];
	if (direction == 1) {
		dice[0] = cp[3];
		dice[2] = cp[0];
		dice[3] = cp[5];
		dice[5] = cp[2];
	}
	else if (direction == 2) {
		dice[0] = cp[2];
		dice[2] = cp[5];
		dice[3] = cp[0];
		dice[5] = cp[3];
	}
	else if (direction == 3) {
		dice[0] = cp[1];
		dice[1] = cp[5];
		dice[4] = cp[0];
		dice[5] = cp[4];
	}
	else {
		dice[0] = cp[4];
		dice[1] = cp[0];
		dice[4] = cp[5];
		dice[5] = cp[1];
	}
}

int main() {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < 6; i++)
			dice[i] = 0;
	int direction;
	for (int i = 0; i < k; i++) {
		cin >> direction;
		x += dir[direction - 1][0];
		y += dir[direction - 1][1];
		if (x < 0 || x >= m || y < 0 || y >= n) {
			x -= dir[direction - 1][0];
			y -= dir[direction - 1][1];
			continue;
		}
		move(direction);
		if (map[y][x] == 0) map[y][x] = dice[5];
		else {
			dice[5] = map[y][x];
			map[y][x] = 0;
		}
		cout << dice[0] << "\n";
	}
}