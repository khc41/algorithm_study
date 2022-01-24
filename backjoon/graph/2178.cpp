#include <iostream>
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

int map[101][101];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int m, n;
bool visited[101][101];
queue<point> q;

void bfs(int x, int y) {
	visited[y][x] = true;
	q.push(point(x, y));
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dir[i][0];
			int ny = p.y + dir[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			else if (map[ny][nx] == 1 && !visited[ny][nx]) {
				map[ny][nx] = map[p.y][p.x] + 1;
				q.push(point(nx, ny));
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	int i, j;
	string s;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0);
	cout << map[n - 1][m - 1] << endl;
}