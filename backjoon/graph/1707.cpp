#include <iostream>
#include <vector>
using namespace std;

#define GREEN 0
#define RED 1
#define BLUE 2

int V, E;
int visited[20001];
vector<int> map[20001];

int dfs(int v, int color) {
	int sum = 0;
	if (visited[v] == GREEN)
		visited[v] = color;
	else{
		if (visited[v] != color) {
			return sum-1;
		}
		return sum;
	}
	
	for (int i = 0; i < map[v].size(); i++) {
			if (visited[v] == BLUE) {
				 sum += dfs(map[v][i], RED);
			}
			else if (visited[v] == RED) {
				sum += dfs(map[v][i], BLUE);

			}
	}
	return sum;
}

int main() {
	int k, tc, i, u, v;
	cin >> k;
	for (tc = 0; tc < k; tc++) {
		int sum = 0;
		cin >> V >> E;
		for (i = 0; i < E; i++) {
			cin >> u >> v;
			map[u].push_back(v); map[v].push_back(u);
		}
		for (i = 1; i <= V; i++) {
			visited[i] = GREEN;
		}

		for (i = 1; i <= V; i++) {
			if (visited[i] == GREEN) sum += dfs(i, BLUE);
		}
		cout << endl;
		if (sum == 0) cout << "YES\n";
		else cout << "NO\n";
		map->clear();
		for (i = 1; i <= V; i++) {
			map[i].clear();
		}
	}
}