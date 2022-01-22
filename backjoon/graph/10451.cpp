#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

vector<int> map[1001];
bool visited[1001];
queue<int> q;

int bfs(int v) {
	visited[v] = true;
	q.push(v);
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i = 0; i < map[p].size(); i++) {
			if (visited[map[p][i]] == false) {
				q.push(map[p][i]);
				visited[map[p][i]] = true;
			}
		}
	}
	return 1;
}

int main() {
	int t, tc, n, i, a;
	cin >> t;
	for (tc = 0; tc < t; tc++) {
		int sum = 0;
		cin >> n;
		memset(visited, false, 1001 * sizeof(bool));
		for (i = 1; i <= n; i++) {
			cin >> a;
			map[i].push_back(a);
		}

		for (i = 1; i <= n; i++) {
			if (visited[i] == false) sum += bfs(i);
		}
		cout << sum << endl;
		map->clear();
		for (i = 1; i <= n; i++) map[i].clear();
	}
}