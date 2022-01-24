#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct point {
	int x;
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int map[1001][1001];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int m, n;
bool visited[1001][1001];
queue<point> q;

void bfs() {
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dir[i][0];
			int ny = p.y + dir[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			else if (map[ny][nx] == 0 && !visited[ny][nx]) {
				map[ny][nx] = map[p.y][p.x] + 1;
				q.push(point(nx, ny));
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	int i, j;
	cin >> m >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push(point(j, i));
		}
	bfs();
	int res = -1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
			else {
				res = max(res, map[i][j]);
			}
		}
	cout << res - 1;
}