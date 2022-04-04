#include <iostream>
#include <queue>

using namespace std;

int n, m;
string map[11];
int dir[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };
queue < pair<pair<int, int>, int>> r;
queue < pair<pair<int, int>, int>> b;
pair<int, int> g;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R') {
				map[i][j] = '.';
				r.push({ {j, i}, 0 });
			}
			else if (map[i][j] == 'B') {
				map[i][j] = '.';
				b.push({ {j, i}, 0 });
			}
			else if (map[i][j] == 'O') {
				g.first = j;
				g.second = i;
			}
		}
	}
	int ans = -1;
	
	while (!r.empty() || !b.empty()) {
		int rx = r.front().first.first;
		int ry = r.front().first.second;
		int rd = r.front().second;
		int bx = b.front().first.first;
		int by = b.front().first.second;
		int bd = b.front().second;

		//cout << rx << " " << ry << "  " << bx << " " << by << "  " << rd << " " << bd << endl;
		if (rd >= 11 && bd >= 11)
			break;
		if ((rx == g.first && ry == g.second) && (bx != g.first || by != g.second)) {
			ans = rd;
			break;
		}
		r.pop(); b.pop();

		for (int i = 0; i < 4; i++) {
			int n_rx = rx + dir[i][0];
			int n_ry = ry + dir[i][1];
			int n_bx = bx + dir[i][0];
			int n_by = by + dir[i][1];
			while (map[n_ry][n_rx] == '.' && (n_ry != by || n_rx != bx)) {
				n_rx += dir[i][0]; n_ry += dir[i][1];
			}
			while (map[n_by][n_bx] == '.' && (n_by != ry || n_bx != rx)) {
				n_bx += dir[i][0]; n_by += dir[i][1];
			}
			int p_rx = 0, p_ry = 0;
			if (map[n_ry][n_rx] == '#') {
				p_rx = n_rx - dir[i][0];
				p_ry = n_ry - dir[i][1];
			}
			else if (n_ry == by && n_rx == bx) {
				if (map[n_by][n_bx] == 'O') {
					p_rx = n_bx;
					p_ry = n_by;
				}
				else{
					p_rx = n_bx - 2 * dir[i][0];
					p_ry = n_by - 2 * dir[i][1];
				}
			}
			else if (map[n_ry][n_rx] == 'O') {
				p_rx = n_rx;
				p_ry = n_ry;
			}
			int p_bx = 0, p_by = 0;

			if (map[n_by][n_bx] == '#') {
				p_bx = n_bx - dir[i][0];
				p_by = n_by - dir[i][1];
			}
			else if (n_by == ry && n_bx == rx) {
				if (map[n_ry][n_rx] == 'O') {
					p_bx = n_rx;
					p_by = n_ry;
				}
				else {
					p_bx = n_rx - 2 * dir[i][0];
					p_by = n_ry - 2 * dir[i][1];		
				}
			}
			else if (map[n_by][n_bx] == 'O') {
				continue;
			}
			if(p_rx != rx || p_ry != ry || p_bx != bx || p_by != by){
				r.push({ { p_rx, p_ry } , rd + 1 }); 
				b.push({ { p_bx, p_by } , bd + 1 });
			}
		}
	}
	cout << ans;
}