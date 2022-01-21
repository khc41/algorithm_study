#include <iostream>

using namespace std;

int n, m;
int visited[1001];
int map[1001][1001];

int dfs(int v) {
	if (visited[v] == true) return 0;
	visited[v] = true;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false && map[v][i] == 1) {
			dfs(i);
		}
	}
	return 1;
}

int main() {
	int u, v, i, j, sum = 0;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		map[u][v] = 1; map[v][u] = 1;
	}

	for (i = 0; i < 1001; i++) visited[i] = false;

	for (i = 1; i <= n; i++) {
		sum += dfs(i);
	}
	cout << sum;
}