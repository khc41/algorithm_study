#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int m[11][11];
int n;
int min_time = 987654321;
struct person {
public:
	int x, y;
	int dis;
	int pick;
	bool is_comp;
	person(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

struct stair {
	int x, y;
	int t;
	stair(int x, int y, int t) {
		this->x = x; this->y = y; this->t = t;
	}
};

int get_dis(person p, stair s) {
	return abs(p.x - s.x) + abs(p.y - s.y);
}

void minus_dis(vector<person>& p) {
	for (int i = 0; i < p.size(); i++)
		p[i].dis--;
}

void select(int depth, vector<person> p, vector<stair> s) {
	if (depth == p.size()) {
		for (int i = 0; i < p.size(); i++) {
			p[i].dis = get_dis(p[i], s[p[i].pick]);
		}
		int time = -1;
		int comp = 0;
		int p_num = p.size();
		queue<int> down[2];
		while (comp < p_num) {
			time++;
			for (int i = 0; i < 2; i++) {
				while (!down[i].empty()) {
					if (down[i].front() <= time) {
						cout << down[i].front() << " ";
						down[i].pop();
						comp++;
					}
					else break;
				}
			}

			for (int i = 0; i < p_num; i++) {
				if (p[i].dis <= 0 && !p[i].is_comp) {
					if (down[p[i].pick].size() < 3){
						p[i].is_comp = true;
						if(p[i].dis == 0)
							down[p[i].pick].push(time + s[p[i].pick].t + 1);
						else
							down[p[i].pick].push(time + s[p[i].pick].t);
					}
				}
			}
			minus_dis(p);
		}
		cout << time << endl << endl;
		min_time = min(time, min_time);
		return;
	}
	p[depth].pick = 0;
	select(depth + 1, p, s);
	p[depth].pick = 1;
	select(depth + 1, p, s);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		min_time = 987654321;
		vector<person> p;
		vector<stair> s;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++){
				cin >> m[i][j];
				if (m[i][j] == 0) continue;
				else if (m[i][j] == 1) p.push_back(person(j, i));
				else s.push_back(stair(j, i, m[i][j]));
			}

		select(0, p, s);
		cout << "#" << test_case << " " << min_time << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}