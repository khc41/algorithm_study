#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[9][9];
int answer = 987654321;
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0, -1} };
struct point {
public: 
	int x;
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
queue<point> q;

int get_blind() {
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0)
				sum++;
	return sum;
}

void see(point cur, int cam, int direction) {
	if (cam == 1) {
		int nx = cur.x + dir[direction][0];
		int ny = cur.y + dir[direction][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6) {
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[direction][0];
			ny += dir[direction][1];
		}
			
	}
	else if (cam == 2) {
		int nx = cur.x + dir[direction][0];
		int ny = cur.y + dir[direction][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[direction][0];
			ny += dir[direction][1];
		}
		nx = cur.x + dir[(direction + 2) % 4][0];
		ny = cur.y + dir[(direction + 2) % 4][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[(direction + 2) % 4][0];
			ny += dir[(direction + 2) % 4][1];
		}
	}
	else if (cam == 3) {
		int nx = cur.x + dir[direction][0];
		int ny = cur.y + dir[direction][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[direction][0];
			ny += dir[direction][1];
		}
		nx = cur.x + dir[(direction + 1) % 4][0];
		ny = cur.y + dir[(direction + 1) % 4][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[(direction + 1) % 4][0];
			ny += dir[(direction + 1) % 4][1];
		}
	}
	else if (cam == 4) {
		int nx = cur.x + dir[direction][0];
		int ny = cur.y + dir[direction][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[direction][0];
			ny += dir[direction][1];
		}
		nx = cur.x + dir[(direction + 1) % 4][0];
		ny = cur.y + dir[(direction + 1) % 4][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[(direction + 1) % 4][0];
			ny += dir[(direction + 1) % 4][1];
		}
		nx = cur.x + dir[(direction + 2) % 4][0];
		ny = cur.y + dir[(direction + 2) % 4][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[(direction + 2) % 4][0];
			ny += dir[(direction + 2) % 4][1];
		}
	}
	else if (cam == 5) {
		int nx = cur.x + dir[direction][0];
		int ny = cur.y + dir[direction][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[direction][0];
			ny += dir[direction][1];
		}
		nx = cur.x + dir[(direction + 1) % 4][0];
		ny = cur.y + dir[(direction + 1) % 4][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[(direction + 1) % 4][0];
			ny += dir[(direction + 1) % 4][1];
		}
		nx = cur.x + dir[(direction + 2) % 4][0];
		ny = cur.y + dir[(direction + 2) % 4][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if (map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[(direction + 2) % 4][0];
			ny += dir[(direction + 2) % 4][1];
		}
		nx = cur.x + dir[(direction + 3) % 4][0];
		ny = cur.y + dir[(direction + 3) % 4][1];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6){
			if(map[ny][nx] == 0)
				map[ny][nx] = 7;
			nx += dir[(direction + 3) % 4][0];
			ny += dir[(direction + 3) % 4][1];
		}
	}
}

void solve() {
	if (q.empty()) {
		answer = min(answer, get_blind());
		return;
	}
	point cur = q.front();
	q.pop();
	int cp[9][9];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cp[i][j] = map[i][j];
	for (int i = 0; i < 4; i++) {
		see(cur, map[cur.y][cur.x], i);
		solve();
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				map[j][k] = cp[j][k];
	}
	q.push(cur);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++){
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] < 6)
				q.push(point(j, i));
		}
	solve();
	cout << answer;
	return 0;
}