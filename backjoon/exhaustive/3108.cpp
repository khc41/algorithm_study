#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int map[2001][2001];
int n;

int dir[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };

void draw(int x1, int x2, int y1, int y2) {
	for (int i = x1; i <= x2; i++) {
		map[y1][i] = 1;
		map[y2][i] = 1;
	}
	for (int i = y1; i <= y2; i++) {
		map[i][x1] = 1;
		map[i][x2] = 1;
	}
}

void dfs(int x, int y) {
	map[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx < 0 || nx > 2000 || ny < 0 || ny > 2000) continue;
		if (map[ny][nx] == 1) 
			dfs(nx, ny);
	}
}

int main() {
	int ans = 0;
	cin >> n;
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		draw(2*(x1 + 500), 2*(x2 + 500), 2*(y1 + 500), 2*(y2 + 500));
	}
	
	for(int i = 0; i <= 2000; i++)
		for (int j = 0; j <= 2000; j++) {
			if (map[i][j] == 1) {
				ans++;
				dfs(j, i);
			}
		}
	if (map[1000][1000] == 2) ans--;

	cout << ans;

}