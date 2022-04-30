
#include <iostream>
#include <vector>

using namespace std;

int dir[8][2] = { {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };
int n, m, k;

struct fire {
public:
	int x, y;
	int m, d, s;
	fire(int r, int c, int m, int s, int d) {
		this->x = r;
		this->y = c;
		this->m = m;
		this->s = s;
		this->d = d;
	}
};

vector<fire> ball;

int main() {
	int answer = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		ball.push_back(fire(c, r, m, s, d));
	}
	int t = 0;
	while (t++ < k) {
        vector<fire> map[51][51];

        for (int i = 0; i < ball.size(); i++) {
            if (ball[i].m <= 0) continue;
            int nx = ball[i].x + (ball[i].s % n) * dir[ball[i].d][0];
            int ny = ball[i].y + (ball[i].s % n) * dir[ball[i].d][1];
            if (nx < 1) nx += n;
            else if (nx > n) nx -= n;
            if (ny < 1) ny += n;
            else if (ny > n) ny -= n;
            ball[i].x = nx;  ball[i].y = ny;
            map[ny][nx].push_back(ball[i]);
        }

        vector<fire> temp;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
                if (map[i][j].empty()) continue;
                if (map[i][j].size() == 1) {
                    temp.push_back(map[i][j][0]);
                    continue;
                }
				int all_m = 0;
				int all_s = 0;
				int size = map[i][j].size();
				int odd = 0;
				int even = 0;
				int direction = 0;
				for (int l = 0; l < size; l++) {
					all_m += map[i][j][l].m;
					all_s += map[i][j][l].s;
					if (map[i][j][l].d % 2 == 0) even++;
					else odd++;
				}
				if (even != 0 && odd != 0) {
					direction = 1;
				}
				if(all_m >=5){
					for (int l = 0; l < 4; l++) {
                        temp.push_back(fire(j, i, all_m / 5, all_s / size, direction + l * 2));
					}
				}
			}
		}
        ball = temp;
	}

	for (int i = 0; i < ball.size(); i++)
		if(ball[i].m > 0)
			answer += ball[i].m;
	cout << answer << endl;
}