#include<iostream>
#include <vector>
using namespace std;

int n, k;
int map[9][9];
bool visited[9][9];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0, -1} };
int answer = 0;

struct p {
public:
	int x;
	int y;
	p(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void dfs(p cur, int depth) {
	answer = max(depth, answer);

	for (int i = 0; i < 4; i++) {
		int nx = cur.x + dir[i][0];
		int ny = cur.y + dir[i][1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if(!visited[ny][nx] && map[cur.y][cur.x] > map[ny][nx]){
			visited[ny][nx] = true;
			dfs(p(nx, ny), depth + 1);
			visited[ny][nx] = false;
		}
	}
}

void solve(p cur) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for(int l = 1; l <= k; l++){
				if (i != cur.y || j != cur.x){
					map[i][j] -= l;
					dfs(cur, 1);
					map[i][j] += l;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int hi = 0;
		answer = 0;
		vector<p> peak;
		cin >> n >> k;

		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				hi = max(hi, map[i][j]);
			}

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				if (map[i][j] == hi) 
					peak.push_back(p(j, i));
			}
		}

		for (int i = 0; i < peak.size(); i++) {
			solve(peak[i]);
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}