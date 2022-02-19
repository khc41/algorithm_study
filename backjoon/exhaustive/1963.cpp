#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define p pair<int, int>

int arr[10001];
bool visit[10001];
vector<int> prime;

bool check(string a, string b) {
	int ret = false;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) {
			if (ret == false)
				ret = true;
			else
				return false;
		}
	}
	return true;
}

int main() {
	int T, tc;
	cin >> T;
	for (int i = 0; i < 10000; i++) {
		arr[i] = i;
	}
	for (int i = 2; i < 10000; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j < 10000; j += i)
			arr[j] = 0;
	}

	for (int i = 1000; i < 10000; i++)
		if (arr[i] != 0) prime.push_back(i);

	for (int tc = 0; tc < T; tc++) {
		int a, b, result = 0;
		cin >> a >> b;
		queue<p> q;
		for (int i = 1000; i < 10000; i++) visit[i] = false;
		q.push({ a, 0 });
		visit[a] = true;
		while (!q.empty()) {
			p n = q.front();
			q.pop();
			if (n.first == b) {
				result = n.second;
				break;
			}
			for (int i = 0; i < prime.size(); i++) {
				if (!visit[prime[i]] && check(to_string(n.first), to_string(prime[i]))) {
					q.push({ prime[i], n.second + 1 });
					visit[prime[i]] = true;
				}
			}
		}
		cout << result << "\n";
	}
}