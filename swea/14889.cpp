#include <iostream>
#include <vector>
using namespace std;

int n;
int s[21][21];
int visited[21];
int ans = 987654321;

void solve(int past, int depth) {
	if (depth == n / 2) {
		int start = 0; int link = 0;
		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				for (int j = 0; j < n; j++) {
					if(visited[j])
						start += s[i][j];
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					if (!visited[j])
						link += s[i][j];
				}
			}
		}
		ans = min(ans, abs(start - link));
		return;
	}
	for (int i = past + 1; i < n; i++) {
		if(!visited[i]){
			visited[i] = true;
			solve(i, depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> s[i][j];

	solve(0, 0);
	cout << ans;
}