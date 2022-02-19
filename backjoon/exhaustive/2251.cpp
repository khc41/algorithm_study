#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int A, B, C;
bool visited[201][201][201];
set<int> ret;

void bfs() {
	queue < pair<pair<int, int>, int>> q;
	q.push({ {0,0} ,C });
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;

		if (a == 0) ret.insert(c);

		// a -> b
		if (a + b > B)
			q.push({ {a + b - B, B}, c });
		else 
			q.push({ {0, a + b}, c });

		// a -> c
		if (a + c > C)
			q.push({ {a + c - C, b}, C });
		else
			q.push({ {0, b}, a + c });

		// b -> a
		if (a + b > A)
			q.push({ {A, a + b - A}, c });
		else
			q.push({ {a + b, 0}, c });

		// b -> c
		if (b + c > C)
			q.push({ {a, b + c - C}, C });
		else
			q.push({ {a, 0}, b + c });

		// c -> a
		if (a + c > A)
			q.push({ {A, b}, a + c - A });
		else
			q.push({ {a + c, b}, 0 });

		// c -> b
		if (c + b > B)
			q.push({ {a, B}, c+ b - B });
		else
			q.push({ {a, c + b}, 0 });
	}
}

int main() {
	
	cin >> A >> B >> C;
	bfs();
	for (auto it = ret.begin(); it != ret.end(); it++)
		cout << *it << " ";
}