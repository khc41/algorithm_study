#include <iostream>
#include <vector>

using namespace std;

int n, m, h;
int map[31][11];
int answer = 987654321;
struct point {
public:
	int x;
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
vector<point> v;

void solve(int idx, int depth) {
	if (depth == 4)
		return;
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int y = 1;
		int x = i;
		while (y <= h) {
			if (map[y][x] == 1) x++;
			else if (map[y][x] == -1) x--;
			y++;
		}
		if (i == x)
			cnt++;
		else
			break;
	}

	if (cnt == n) {
		answer = min(answer, depth);
	}

	for(int i = idx; i < v.size(); i++) {
		point cur = v[i];
		if(map[cur.y][cur.x] == 0 && map[cur.y][cur.x + 1] == 0){
			map[cur.y][cur.x] = 1; map[cur.y][cur.x + 1] = -1;
			solve(i+1, depth + 1);
			map[cur.y][cur.x] = 0; map[cur.y][cur.x + 1] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[a][b + 1] = -1;
	}

	for (int i = 1; i <= h; i++)
		for (int j = 1; j < n; j++)
			if (map[i][j] == 0)
				v.push_back(point(j, i));

	solve(0,0);
	if (answer == 987654321)
		cout << "-1";
	else cout << answer;
}