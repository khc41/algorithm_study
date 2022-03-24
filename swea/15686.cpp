#include <iostream>
#include <vector>

using namespace std;

int n, m;
struct p {
public :
	int x; 
	int y;
	p(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
vector<p> house;
vector<p> chicken;
int answer = 987654321;

int distance(p a, p b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int get_chicken_distance(vector<int>& pick) {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int min_distance = 987654321;
		for (int j = 0; j < pick.size(); j++) {
			min_distance = min(min_distance, distance(chicken[pick[j]], house[i]));
		}
		sum += min_distance;
	}
	return sum;
}



void solve(int idx, int depth, vector<int>& pick) {
	if (pick.size() == m){
		answer = min(answer, get_chicken_distance(pick));
		return;
	}
	if (depth == chicken.size()) return;
	vector<int> cp;
	for (int i = 0; i < pick.size(); i++) cp.push_back(pick[i]);
	cp.push_back(idx);
	solve(idx + 1, depth + 1, cp);
	solve(idx + 1, depth + 1, pick);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int in;
			cin >> in;
			if (in == 1) house.push_back(p(j, i));
			else if (in == 2) chicken.push_back(p(j, i));
		}
	}

	vector<int> pick;
	solve(0, 0, pick);
	cout << answer;
}