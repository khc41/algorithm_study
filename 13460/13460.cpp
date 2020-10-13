#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

struct ball {
	int depth;
	int rx, ry, bx, by;
};

int answer = -1;
int map[10][10];
int hx, hy, frx, fry, fbx, fby;
bool visit[10][10][10][10];
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void move(int &x, int &y, int d) {
	while (1) {
		x += dir[d][0]; y += dir[d][1];
		if (map[x][y] == 1) {
			x -= dir[d][0]; y -= dir[d][1];
			break;
		}
		else if (map[x][y] == 2)
			break;
	}
}

int main() {
	int n, m, i, j;
	string s;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < m; j++) {
			switch (s[j]) {
			case '.':
				map[i][j] = 0;
				break;
			case '#':
				map[i][j] = 1;
				break;
			case 'O':
				map[i][j] = 2; hx = i; hy = j;
				break;
			case 'R':
				frx = i; fry = j;
				break;
			case 'B':
				fbx = i; fby = j;
				break;
			}
		}
	}

	queue<ball> q;
	q.push({ 0, frx, fry, fbx, fby });
	visit[frx][fry][fbx][fby] = true;

	while (!q.empty()) {
		ball cur = q.front(); q.pop();
		
		if (cur.depth > 10)
			break;

		if (cur.rx == hx && cur.ry == hy) {
			answer = cur.depth;
			break;
		}

		for (i = 0; i < 4; i++) {
			int rx = cur.rx, ry = cur.ry;
			int bx = cur.bx, by = cur.by;
			move(rx, ry, i); move(bx, by, i);

			if (bx == hx && by == hy)
				continue;

			if (rx == bx && ry == by) {
				switch (i) {
				case 0:
					cur.rx < cur.bx ? rx-- : bx--; break;
				case 1:
					cur.ry < cur.by ? ry-- : by--; break;
				case 2:
					cur.rx > cur.bx ? rx++ : bx++; break;
				case 3:
					cur.ry > cur.by ? ry++ : by++; break;
				}
			}

			if (!visit[rx][ry][bx][by]) {
				ball next = { cur.depth+1, rx, ry, bx, by };
				q.push(next);
				visit[rx][ry][bx][by] = true;
			}
		}
	}
	cout << answer;
}