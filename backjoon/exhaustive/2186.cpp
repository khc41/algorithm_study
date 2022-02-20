#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, k;

string map[101];
string goal;
int dp[101][101][81];

pair<int,int> dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int dfs(int y, int x, int depth) {
	int& ret = dp[y][x][depth];
	if (ret != -1) return ret;
	if (depth == goal.size()) return 1;

	ret = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x;
		int ty = y;
		for (int j = 0; j < k; j++) {
			int nx = tx + dir[i].first;
			int ny = ty + dir[i].second;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
			if ( map[ny][nx] == goal[depth]){
				ret += dfs(ny, nx, depth + 1);
			}
			ty = ny;
			tx = nx;
		}
	}
	return ret;
}

int main() {
	int ans = 0;
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	cin >> goal;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == goal[0]){
				ans += dfs(i, j, 1);
			}
		}
	}
	cout << ans;
}