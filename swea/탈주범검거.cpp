#include<iostream>
#include <vector>
#include <queue>

using namespace std;

struct cell {
public:
	int x, y;
	int d[4];
	cell() {}
	cell(int x, int y, int u, int r, int d, int l) {
		this->x = x;
		this->y = y;
		this->d[0] = u;
		this->d[1] = r;
		this->d[2] = d;
		this->d[3] = l;
	}
};

cell map[51][51];
int n, m, r, c, l;
int answer = 0;
int visited[51][51];
int dir[4][2] = { {0,-1}, {1,0}, {0,1}, {-1, 0} };

cell make_cell(int x, int y, int num) {
	if (num == 1) return cell(x, y, 1, 1, 1, 1);
	else if (num == 2) return cell(x, y, 1, 0, 1, 0);
	else if (num == 3) return cell(x, y, 0, 1, 0, 1);
	else if (num == 4) return cell(x, y, 1, 1, 0, 0);
	else if (num == 5) return cell(x, y, 0, 1, 1, 0);
	else if (num == 6) return cell(x, y, 0, 0, 1, 1);
	else if (num == 7) return cell(x, y, 1, 0, 0, 1);
	else return cell(x, y, 0, 0, 0, 0);
}

void bfs(int x, int y, int t) {
	queue<cell> q;
	int time = 1;
	q.push(map[y][x]);
	answer++;
	visited[y][x] = true;
	while (!q.empty() && time < t) {
		int qs = q.size();

		for (int move = 0; move < qs; move++) {
			cell cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				if (cur.d[i] == 1) {
					int nx = cur.x + dir[i][0];
					int ny = cur.y + dir[i][1];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (!visited[ny][nx] && map[ny][nx].d[(i + 2) % 4] == 1) {
						q.push(map[ny][nx]);
						visited[ny][nx] = true;
						answer++;
					}
				}
			}
		}

		time++;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = 0;
		cin >> n >> m >> r >> c >> l;
		for(int i = 0; i < n ; i++)
			for (int j = 0; j < m; j++) {
				int in;
				cin >> in; 
				map[i][j] = make_cell(j, i, in);
				visited[i][j] = false;
			}

		bfs(c, r, l);
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}