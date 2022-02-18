#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define p pair<int, int>
int n, k;
queue<p> q;
int dp[100001];

int move(int num) {
	int t = 0;
	q.push({ num, t });
	while (!q.empty()) {
		p m = q.front();
		dp[m.first] = m.second;
		if (m.first == k) {
			t = m.second;
			break;
		}
		q.pop();
		int a = 2 * m.first; int b = m.first + 1; int c = m.first - 1;
		if(!(a < 0 || a > 100000) && (dp[a] > m.second + 1 || dp[a] == 0))
			q.push({ a, m.second + 1});
		if (!(b < 0 || b > 100000) && (dp[b] > m.second + 1 || dp[b] == 0))
			q.push({b, m.second + 1});
		if (!(c < 0 || c > 100000) && (dp[c] > m.second + 1 || dp[c] == 0))
			q.push({c, m.second + 1});
	}
	return t;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i <= 100000; i++) dp[i] = 0;
	cout << move(n);
}