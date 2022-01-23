#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

bool visited[100001];
bool done[100001];
int map[100001];
int n, cnt;

void dfs(int v) {
	visited[v] = true;
	int next = map[v];
	if (!visited[next]) dfs(next);
	else if (!done[next]){
		for (int i = next; i != v; i = map[i]) {
			cnt++;
		}
		cnt++;
	}
	done[v] = true;
}

int main() {
	int t, tc, i;
	cin >> t;
	for (tc = 0; tc < t; tc++) {
		cnt = 0;
		cin >> n;
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
		for (i = 1; i <= n; i++) 
			cin >> map[i];
		for (i = 1; i <= n; i++) 
			if(!visited[i])
				dfs(i);
		cout << n - cnt << endl;
	}
}