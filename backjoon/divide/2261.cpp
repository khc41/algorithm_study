#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
public :
	int x;
	int y;
	bool operator < (const point& p) const {
		if (x == p.x)
			return y < p.y;
		else
			return x < p.x;
	}
};

int distance(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compare(point a, point b) {
	return a.y < b.y;
}

int searchAll(vector<point>& v, int s, int e) {
	int minDist = -1;
	for (int i = s; i <= e - 1; i++) {
		for (int j = i + 1; j <= e; j++) {
			int dist = distance(v[i], v[j]);
			if (minDist == -1 || dist < minDist) {
				minDist = dist;
			}
		}
	}
	return minDist;
}

int searchPoint(vector<point>& v, int s, int e) {
	int cnt = e - s + 1;
	if (cnt <= 3)
		return searchAll(v, s, e);
	int mid = (s + e) / 2;
	int left = searchPoint(v, s, mid);
	int right = searchPoint(v, mid + 1, e);

	int answer = min(left, right);

	vector<point> near;

	for (int i = s; i <= e; i++) {
		int xDis = v[i].x - v[mid].x;
		if (xDis * xDis < answer)
			near.push_back(v[i]);
	}

	int size = near.size();
	sort(near.begin(), near.end(), compare);
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			int yDis = near[j].y - near[i].y;
			if (yDis * yDis < answer) {
				int dist = distance(near[j], near[i]);
				if (dist < answer)
					answer = dist;
			}
			else
				break;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<point> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}
	sort(v.begin(), v.end());
	int answer = searchPoint(v, 0, n - 1);
	cout << answer;
}