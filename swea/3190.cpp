#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k, l;
int b[101][101];
int a[101];
queue<pair<int, char>> d;
vector<pair<int, int>> s;

void change_dir(int& x, int& y, char d) {
	if (x == 1 && y == 0) {
		if (d == 'D') {
			x = 0; y = 1;
		}
		else {
			x = 0; y = -1;
		}
	}
	else if (x == -1 && y == 0) {
		if (d == 'D') {
			x = 0; y = -1;
		}
		else {
			x = 0; y = 1;
		}
	}
	else if (x == 0 && y == 1) {
		if (d == 'D') {
			x = -1; y = 0;
		}
		else {
			x = 1; y = 0;
		}
	}
	else if (x == 0 && y == -1) {
		if (d == 'D') {
			x = 1; y = 0;
		}
		else {
			x = -1; y = 0;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> y >> x;
		b[y - 1][x - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x; char c;
		cin >> x >> c;
		d.push({ x, c });
	}
	s.push_back({ 0,0 });
	int x_p = 1;
	int y_p = 0;
	int time = 0;
	while (1) {
		time++;
		int nx = s.front().first + x_p;
		int ny = s.front().second + y_p;

		if (ny >= n || ny < 0 || nx >= n || nx < 0) break;
		if (b[ny][nx] == 2) break;

		s.insert(s.begin(), { nx, ny });
		if (b[ny][nx] != 1) {
			int tx = s.back().first;
			int ty = s.back().second;
			b[ty][tx] = 0;
			s.erase(s.begin() + s.size() - 1);
		}
		b[ny][nx] = 2;

		if (!d.empty()) {
			if (d.front().first == time) {
				change_dir(x_p, y_p, d.front().second);
				d.pop();
			}
		}
	}
	cout << time;
}