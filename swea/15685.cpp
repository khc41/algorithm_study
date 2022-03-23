#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int dir[4][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
int map[101][101];
int answer = 0;

void get_square() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 &&
				map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				answer++;
		}
	}
}

void dragon_curv(int x, int y, int d, int g, int depth,  vector<int>& v) {
	if (g + 1 == depth) {
		return;
	}
	queue<int> q;
	if (depth != 0) {
		for (int i = v.size() - 1; i >= 0; i--) {
			q.push((v[i] + 4 + 1) % 4);
		}
	}
	else q.push(d);
	int nx = x; int ny = y;
	while (!q.empty()) {
		int direction = q.front();
		v.push_back(direction);
		q.pop();
		nx += dir[direction][0];
		ny += dir[direction][1];
		map[ny][nx] = 1;
	}
	dragon_curv(nx, ny, d, g, depth + 1, v);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		vector<int> v;
		cin >> x >> y >> d >> g;
		map[y][x] = 1;
		dragon_curv(x, y, d, g, 0, v);
	}

	get_square();
	cout << answer;
}