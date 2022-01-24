#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct point {
public:
	int x;
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int n;
int map[101][101];
bool visited[101][101];
queue<point> q;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void bfs_land(int x, int y, int value) {
	visited[y][x] = true;
	map[y][x] = value;
	q.push(point(x, y));
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dir[i][0];
			int ny = p.y + dir[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}
			if (!visited[ny][nx] && map[ny][nx] == 1) {
				map[ny][nx] = value;
				visited[ny][nx] = true;
				q.push(point(nx, ny));
			}
		}
	}
}

int bfs(int value) {
	q = queue<point>();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == value) {
				q.push(point(j, i));
				visited[i][j] = true;
			}
		}
	}
	int result = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int j = 0; j < qSize; j++) {
			point p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dir[i][0];
				int ny = p.y + dir[i][1];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (map[ny][nx] != 0 && map[ny][nx] != value)
					return result;
				else if (!visited[ny][nx] && map[ny][nx] == 0) {
					visited[ny][nx] = true;
					q.push(point(nx, ny));

				}
			}
		}
		result++;
	}
}

int main() {
	int i, j, k;
	int cnt = 1;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				bfs_land(j, i, cnt++);
			}
		}
	}
	int res = 987654321;
	for (i = 1; i < cnt; i++) {
		memset(visited, false, sizeof(visited));
		res = min(res, bfs(i));
	}

	cout << res;
}