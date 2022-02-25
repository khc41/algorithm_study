#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool visit[14];
int num[14];
int k;
int ans[6];

void dfs(int n, int depth) {
	ans[depth] = num[n];
	if (depth == 5) {
		for (int i = 0; i < 6; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = n + 1; i < k; i++) {
		dfs(i, depth + 1);
	}
	visit[n] = false;
}

int main() {
	cin >> k;
	while (k != 0) {
		memset(num, 0, sizeof(num));
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}
		for (int i = 0; i < k - 5; i++){
			dfs(i, 0);
		}
		cout << "\n";
		cin >> k;
	}
}