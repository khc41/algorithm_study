#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std; 

struct point {
	int x; 
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
int n;
int map[26][26];
bool visited[26][26];
int dir[4][2] = { {1, 0}, {0,1}, {-1,0}, {0, -1} };
int sum;
vector<int> ans;
queue<point> q;
void bfs(point v) {
	q.push(v);
	visited[v.y][v.x] = true;
	sum++;
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			point next(p.x + dir[i][0], p.y + dir[i][1]);
			if (next.x <= n && next.x >= 0 && next.y <= n && next.y >= 0 
				&& !visited[next.y][next.x] && map[next.y][next.x] == 1) {
				visited[next.y][next.x] = true;
				sum++;
				q.push(next);
			}
		}
	}
}

int main() {
	int i, j;
	string s;
	cin >> n;
	memset(visited, false, sizeof(visited));
	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < n; j++) 
			map[i][j] = s[j] - '0';
	}
	for ( i = 0 ; i < n; i ++)
		for (j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				sum = 0;
				bfs(point(j, i));
				ans.push_back(sum);
			}
		}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}