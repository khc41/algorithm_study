#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[9][9];
int dir[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };
int ans = 0;

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 2)
				q.push({ j, i });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx <0 || nx >= m || ny <0 || ny >= n) continue;
			if (map[ny][nx] == 0) {
				map[ny][nx] = 2;
				q.push({ nx, ny });
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0){
				sum++;
			}
	ans = max(ans, sum);
}

void solve(int x, int y, int depth) {
	if (depth == 3) {
		int cp[9][9];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cp[i][j] = map[i][j];
		bfs();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				map[i][j] = cp[i][j];
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				solve(j, i, depth + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	solve(0, 0, 0);
	cout << ans;
}