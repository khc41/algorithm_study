#include <iostream>
#include <vector>
using namespace std;

vector<int> map[100001];
bool visited[100001];
int parent[100001];

void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < map[v].size(); i++) {
		int next = map[v][i];
		if(!visited[next]){
			parent[next] = v;
			dfs(next);
		}
	}
}

int main() {
	int n, i, a, b;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;
		map[a].push_back(b); map[b].push_back(a);
	}
	dfs(1);
	for (i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
}