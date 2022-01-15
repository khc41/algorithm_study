#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class point {
public :
	int x;
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool compare(point& a, point& b) {
	if (a.y < b.y) return true;
	else if (a.y == b.y) {
		if (a.x < b.x) return true;
		else return false;
	}
	else return false;
}

int main() {
	int n, i, x, y;
	cin >> n;
	vector<point>p;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		p.push_back(point(x, y));
	}
	sort(p.begin(), p.end(), compare);
	for (i = 0; i < n; i++) {
		printf("%d %d\n", p[i].x, p[i].y);
	}
}