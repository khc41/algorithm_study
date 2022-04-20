#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
public:
	int x, y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int map[21][21];
int n, m;
int answer = 0;
vector<point> house;

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) map[i][j] = 0;
	answer = 0;
	house.clear();
}

void sequrity(point p) {
	bool visited[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	queue<pair<point, int>> q;
	int cnt = 0;
	if (map[p.y][p.x] == 1) {
		cnt++;
	}
	q.push({ p, 1 });
	visited[p.y][p.x] = true;

	while (!q.empty()) {
		point cur = q.front().first;
		int k = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dir[i][0];
			int ny = cur.y + dir[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ point(nx, ny), k + 1 });
				if (map[ny][nx] == 1) {
					cnt++;
				}
			}
		}
		if (!q.empty()) {
			if (k != q.front().second) {
				k++;
				cout << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++)
						cout << visited[i][j] << " ";
					cout << endl;
				}
				cout << cnt << " " << k << " " << (k * k + (k - 1) * (k - 1)) << " " << cnt * m << endl;
				if (cnt * m >= (k * k + (k - 1) * (k - 1))) {

					if (answer < cnt) {

					}
					answer = max(answer, cnt);
				}
				k--;
			}
		}
		if (k > n + 1) break;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) house.push_back(point(j, i));
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sequrity(point(j,i));
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}