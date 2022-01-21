#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
int map[1001][1001];
bool visited[1001];
queue<int> q;

void clear() {
	for (int i = 0; i < 1001; i++) visited[i] = false;
}

int dfs(int v) {
	cout << v << " ";
	visited[v] = true;
	for (int i = 0; i <= n; i++) {
		if (map[v][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
	return 0;
}

int bfs(int v) {
	q.push(v);
	cout << v << " ";
	visited[v] = true;
	
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (int i = 0; i <= n; i++) {
			if (map[num][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
	return 0;
}

int main() {
	int i, a, b;
	cin >> n >> m >> v;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	clear();
	dfs(v);
	cout << "\n";
	clear();
	bfs(v);
}
