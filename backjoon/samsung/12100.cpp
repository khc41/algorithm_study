#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int n;
int **map;
int ans = 0;

void move_left(int ** map) {
	// left
	for (int i = 0; i < n; i++) {
		bool check = false;
		stack<int> s;
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				if (!s.empty() && !check) {
					int cur = s.top();
					if (cur == map[i][j]) {
						s.pop();
						int sum = cur + map[i][j];
						if (sum > ans) ans = sum;
						s.push(sum);
						check = true;
					}
					else
						s.push(map[i][j]);
				}
				else {
					check = false;
					s.push(map[i][j]);
				}
			}
			map[i][j] = 0;
		}
		while (!s.empty()) {
			map[i][s.size() - 1] = s.top();
			s.pop();
		}
	}
}

void move_up(int** map) {
	// up
	for (int i = 0; i < n; i++) {
		bool check = false;
		stack<int> s;
		for (int j = 0; j < n; j++) {
			if (map[j][i] != 0) {
				if (!s.empty() && !check) {
					int cur = s.top();
					if (cur == map[j][i]) {
						s.pop();
						int sum = cur + map[j][i];
						if (sum > ans) ans = sum;
						s.push(sum);
						check = true;
					}
					else 
						s.push(map[j][i]);
					
				}
				else {
				check = false;
					s.push(map[j][i]);
				}
			}
			map[j][i] = 0;
		}
		while (!s.empty()) {
			map[s.size() - 1][i] = s.top();
			s.pop();
		}
	}
}

void move_right(int** map) {
	// right
	for (int i = n-1; i >= 0; i--) {
		bool check = false;
		stack<int> s;
		for (int j = n -1; j >= 0; j--) {
			if (map[i][j] != 0) {
				if (!s.empty() && !check) {
					int cur = s.top();
					if (cur == map[i][j]) {
						s.pop();
						int sum = cur + map[i][j];
						if (sum > ans) ans = sum;
						s.push(sum);
						check = true;
					}
					else
						s.push(map[i][j]);
					
				}
				else {
				check = false;
					s.push(map[i][j]);
				}
			}
			map[i][j] = 0;
		}
		while (!s.empty()) {
			map[i][n - s.size()] = s.top();
			s.pop();
		}
	}
}

void move_down(int** map) {
	// down
	for (int i = n-1; i >=0; i--) {
		bool check = false;
		stack<int> s;
		for (int j = n-1; j >=0; j--) {
			if (map[j][i] != 0) {
				if (!s.empty() && !check) {
					int cur = s.top();
					if (cur == map[j][i]) {
						s.pop();
						int sum = cur + map[j][i];
						if (sum > ans) ans = sum;
						s.push(sum);
						check = true;
					}
					else
						s.push(map[j][i]);
					
				}
				else {
				check = false;
					s.push(map[j][i]);
				}
			}
			map[j][i] = 0;
		}
		while (!s.empty()) {
			map[n - s.size()][i] = s.top();
			s.pop();
		}
	}
}

void copy(int** src, int** dst) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dst[i][j] = src[i][j];
}

void solve(int** m, int depth) {
	if (depth == 5) return;
	int** cp;
	cp = new int* [n];
	for (int i = 0; i < n; i++)
		cp[i] = new int[n];
	copy(m, cp);
	move_left(cp);
	solve(cp, depth + 1);
	copy(m, cp);
	move_right(cp);
	solve(cp, depth + 1);
	copy(m, cp);
	move_up(cp);
	solve(cp, depth + 1);
	copy(m, cp);
	move_down(cp);
	solve(cp, depth + 1);
}

int main() {
	cin >> n;
	map = new int* [n]; 
	for(int i = 0; i < n; i++) 
		map[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			ans = max(map[i][j], ans);
		}
	}
	solve(map, 0);
	cout << ans;
}