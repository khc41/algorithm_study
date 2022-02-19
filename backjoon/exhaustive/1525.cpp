#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

const int TARGET = 123456789;

typedef struct {
	int y, x;
}dir;

dir moveDir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int main() {
	int s = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
			int in;
			cin >> in;
			if (in == 0) in = 9;
			s = s * 10 + in;
		}
	queue<int> q;
	map<int, int> visited;
	q.push(s);
	visited[s] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == TARGET) 
			break;
		string s = to_string(cur);
		int z = s.find('9');
		int y = z / 3;
		int x = z % 3;

		for (int i = 0; i < 4; i++) {
			int ny = y + moveDir[i].y;
			int nx = x + moveDir[i].x;
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				string t = s;
				swap(t[y * 3 + x], t[ny * 3 + nx]);
				int next = stoi(t);
				if (!visited.count(next)) {
					visited[next] = visited[cur] + 1;
					q.push(next);
				}
			}
		}
	}
	if (!visited.count(TARGET))
		cout << -1 << "\n";
	else
		cout << visited[TARGET] << "\n";
}