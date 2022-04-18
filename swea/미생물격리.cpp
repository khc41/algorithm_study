#include <iostream>	
#include <vector>
#include <stack>
using namespace std;

struct micro {
public:
	int x, y;
	int direction;
	int value;
	micro() {}
	micro(int x, int y, int direction, int value) {
		this->x = x;
		this->y = y;
		this->direction = direction;
		this->value = value;
	}
};

int change_dir(int direction) {
	if (direction == 0) return 1;
	else if (direction == 1) return 0;
	else if (direction == 2) return 3;
	else return 2;
}

int dir[4][2] = { {0, -1},  {0, 1}, {-1, 0}, {1, 0 } };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m, k, x, y, direction, value;
		int time = 0;
		vector<micro*> map[101][101];
		micro micros[1001];
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			cin >> y >> x >> value >> direction;
			micros[i].x = x; micros[i].y = y; micros[i].value = value; micros[i].direction = direction - 1;
		}
		cout << endl;
		while (time++ < m) {
			for (int i = 0; i < k; i++) {
				if (micros[i].value == 0) continue;
				micros[i].x += dir[micros[i].direction][0];
				micros[i].y += dir[micros[i].direction][1];
				if (micros[i].y == 0 || micros[i].y == n - 1 
					|| micros[i].x == 0 || micros[i].x == n - 1) {
					micros[i].value /= 2;
					micros[i].direction = change_dir(micros[i].direction);
				}
				map[micros[i].y][micros[i].x].push_back(&micros[i]);
			}

			for (int i = 0; i < n; i++) {        
				for (int j = 0; j < n; j++) {
					if(!map[i][j].empty() && map[i][j].size() > 1){
						int n_dir = 0; 
						int sum = 0;
						int max_v = 0;
						for (int l = 0; l < map[i][j].size(); l++) {
							if (max_v < map[i][j][l]->value) {
								max_v = map[i][j][l]->value;
								n_dir = map[i][j][l]->direction;
							}
							sum += map[i][j][l]->value;
							map[i][j][l]->value = 0;
						}
						map[i][j][0]->value = sum;
						map[i][j][0]->direction = n_dir;
					}
					map[i][j].clear();
				}
			}
			for (int i = 0; i < k; i++)
				cout << micros[i].x << " " << micros[i].y << " " << micros[i].value << endl;
			cout << endl;
		}
		int ret = 0;
		for (int i = 0; i < k; i++)
			ret += micros[i].value;
		cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;
}