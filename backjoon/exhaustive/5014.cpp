#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1000001;

int f, s, g, u, d;
int visited[MAX];

int bfs() {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == g) {
			return visited[cur] - 1;
		}
		int next[2] = { cur + u, cur - d };
		for (int i = 0; i < 2; i++) {
			if (next[i] >= 1 && next[i] <= f && visited[next[i]] == 0) {
				visited[next[i]] = visited[cur] + 1;
				q.push(next[i]);
			}
		}
	}
	return -1;
}

int main() {

	cin >> f >> s >> g >> u >> d;
	int ans = bfs();
	if (ans == -1) cout << "use the stairs";
	else cout << ans;
}