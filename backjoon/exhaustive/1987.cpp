#include <iostream>
#include <string>
using namespace std;

int r, c;
int dir[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };
string board[21];
bool visited[30];

int ans = 1;

void dfs(int x, int y, int depth) {
	visited[board[y][x] - 'A'] = true;
	ans = max(ans, depth);
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
		if(!visited[board[ny][nx] - 'A'] ){
			dfs(nx, ny, depth+1);
			visited[board[ny][nx] - 'A'] = false;
		}
	}
	return;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	dfs(0, 0, 1);
	cout << ans;
}