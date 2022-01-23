#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[51][51];
bool visited[51][51];
int dir[8][2] = { {1 , 0}, {-1,0} , {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };
int w, h;

void dfs(int x, int y) {
	visited[y][x] = true;
	for (int i = 0; i < 8; i++) {
		int nx = dir[i][0] + x;
		int ny = dir[i][1] + y;
		if (nx < 0 || nx > w || ny < 0 || ny > h)
			continue;
		else if (!visited[ny][nx] && map[ny][nx] == 1)
			dfs(nx, ny);
	}
}

int main() {
	int i, j;
	cin >> w >> h;
	while (w != 0 && h != 0) {
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
		for (i = 0; i < h; i++) 
			for (j = 0; j < w; j++) 
				cin >> map[i][j];
		int sum = 0;
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j] == 1) {
					dfs(j, i);
					sum++;
				}
			}
		cout << sum << "\n";
		cin >> w >> h;
	}
}