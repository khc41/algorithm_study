#include <iostream>
#include <queue>

using namespace std;

int n, m, r, c, d;
int map[51][51];
int dir[4][2] = { {0, -1}, {1,0}, {0,1}, {-1,0} };
int ans = 0;

struct clean {
public :
	int x;
	int y;
	int dir;
	clean(int x, int y, int dir) {
		this->x = x;
		this->y = y;
		this->dir = dir;
	}
};

void move() {
	queue<clean> q;
	q.push(clean(c, r, d));
	map[r][c] = 2;
	ans++;
	while (!q.empty()) {
		clean cur = q.front();
		q.pop();
		bool is_move = false;
		for (int i = 0; i < 4; i++) {
			int n_dir = (cur.dir + 3) % 4;
			int nx = cur.x + dir[n_dir][0];
			int ny = cur.y + dir[n_dir][1];
			if (nx < 0 || nx > m || ny < 0 || ny > n) continue;
			if (map[ny][nx] == 0) {
				is_move = true;
				map[ny][nx] = 2;
				q.push(clean(nx, ny, n_dir));
				ans++;
				break;
			}
			else {
				cur.dir = n_dir;
			}
		}
		if (!is_move) {
			int n_dir = (cur.dir + 2) % 4;
			int nx = cur.x + dir[n_dir][0];
			int ny = cur.y + dir[n_dir][1];
			if (nx < 0 || nx > m || ny < 0 || ny > n || map[ny][nx] == 1) break;
			q.push(clean(nx, ny, cur.dir));
		}
	}
}

int main() {
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	move();
	cout << ans;
}