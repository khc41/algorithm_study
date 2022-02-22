#include <iostream>
#include <queue>

using namespace std;


int map[9][9];
bool row[9][9];
bool col[9][9];
bool square[9][9];

void dfs(int n) {
	int x = n / 9;
	int y = n % 9;
	if (n == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	if (map[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false) {
				row[x][i] = true;
				col[y][i] = true;
				square[(x / 3) * 3 + (y / 3)][i] = true;
				map[x][y] = i;
				dfs(n + 1);
				map[x][y] = 0;
				row[x][i] = false;
				col[y][i] = false;
				square[(x / 3) * 3 + (y / 3)][i] = false;
			}
		}
	}
	else
		dfs(n + 1);
}

int main() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0)
			{
				row[i][map[i][j]] = true;
				col[j][map[i][j]] = true;
				square[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
			}
		}
	}

	dfs(0);
}