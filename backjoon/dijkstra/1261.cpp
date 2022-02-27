#include <iostream>
#include <queue>

using namespace std;

int n, m;
int dir[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };
int map[101][101];
int dist[101][101];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	dist[y][x] = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0];
			int ny = cy + dir[i][1];
			if (nx < 0 || ny < 0 || ny >= m || nx >= n) continue;
			if (map[ny][nx] == 1) {
				if (dist[ny][nx] > dist[cy][cx] + 1){
					dist[ny][nx] = dist[cy][cx] + 1;
					q.push({ nx, ny });
				}
			}
			else if( map[ny][nx] == 0){
				if (dist[ny][nx] > dist[cy][cx]) {
					dist[ny][nx] = dist[cy][cx];
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j] - '0';
			dist[i][j] = 987654321;
		}
	}
	bfs(0, 0);
	cout << dist[m - 1][n - 1];
}