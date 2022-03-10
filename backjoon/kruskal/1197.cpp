#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;

struct edge {
public :
	int node[2];
	int dist;
	edge(int a, int b, int dist) {
		this->node[0] = a;
		this->node[1] = b;
		this->dist = dist;
	}

	bool operator <(edge& edge) {
		return this->dist < edge.dist;
	}
};

int get_parent(int* parent, int child) {
	if (parent[child] == child) return child;
	return get_parent(parent, parent[child]);
}

void union_parent(int* parent, int a, int b) {
	a = get_parent(parent, a);
	b = get_parent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(int* parent, int a, int b) {
	int l = get_parent(parent, a);
	int r = get_parent(parent, b);
	if (l == r) return true;
	else return false;
}

int main() {
	int a, b, c;
	cin >> v >> e;
	vector<edge> line;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		line.push_back(edge(a, b, c));
	}
	sort(line.begin(), line.end());

	int *parent = new int[v];
	for (int i = 0; i < v; i++)
		parent[i] = i;
	int sum = 0;
	for (int i = 0; i < line.size(); i++) {
		if (!find(parent, line[i].node[0] - 1, line[i].node[1] - 1)) {
			sum += line[i].dist;
			union_parent(parent, line[i].node[0] - 1, line[i].node[1] - 1);
		}
	}
	cout << sum;
}