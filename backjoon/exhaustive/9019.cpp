#include <iostream>	
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define p pair<int, string>

bool visited[10001];

int d(int n) {
	return 2 * n % 10000;
}
int s(int n) {
	n = n - 1;
	if (n < 0)
		return 9999;
	else
		return n;
}
int l(int n) {
	n *= 10;
	if (n >= 10000) {
		return n = n % 10000 + n / 10000;
	}
	else
		return n;
}
int r(double n) {
	int mod = (int)n % 10;
	n /= 10;
	if (n - floor(n) != 0) {
		return n = floor(n) + mod * 1000;
	}
	else
		return n;
}

int main() {
	int T, tc;
	cin >> T;
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (tc = 0; tc < T; tc++) {
		int a, b;
		string ret = "";
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		queue<p> q;
		q.push({ a, "" });
		visited[(int)a] = true;

		while (!q.empty()) {
			p n = q.front();
			q.pop();
			if (n.first == b) {
				ret = n.second;
				break;
			}
			int a = d(n.first); int b = s(n.first); int c = l(n.first); int d = r(n.first);
			if (!visited[a] && a >= 0 && a < 10000) {
				visited[a] = true;
				q.push({ a, n.second + "D" });
			}
			if (!visited[b] && b >= 0 && b < 10000) {
				visited[b] = true;
				q.push({ b, n.second + "S" });
			}
			if (!visited[c] && c >= 0 && c < 10000) {
				visited[c] = true;
				q.push({ c, n.second + "L" });
			}
			if (!visited[d] && d >= 0 && d < 10000) {
				visited[d] = true;
				q.push({ d, n.second + "R" });
			}
		}
		cout << ret << endl;
	}
}