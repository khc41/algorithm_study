#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n;

void init(vector<long long>& tree, vector<long long>& v, int node, int start, int end) {
	if (start == end) tree[node] = start;
	else {
		int mid = (start + end) / 2;
		init(tree, v, 2 * node, start, mid);
		init(tree, v, 2 * node + 1, mid + 1, end);
		if (v[tree[2 * node]] < v[tree[2 * node + 1]]) tree[node] = tree[2 * node];
		else tree[node] = tree[2 * node + 1];
	}
}

int query(vector<long long>& tree, vector<long long>& v, int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return tree[node];
	else if (right < start || end < left) return -1;

	int mid = (start + end) / 2;
	int l = query(tree, v, 2 * node, start, mid, left, right);
	int r = query(tree, v, 2 * node + 1, mid + 1, end, left, right);
	if (l == -1) return r;
	else if (r == -1) return l;
	else if (v[l] < v[r]) return l;
	else return r;
}

long long get_max_area(vector<long long>& tree, vector<long long>& v, int start, int end) {
	int idx = query(tree, v, 1, 1, n, start, end);
	long long area = (end - start + 1) * v[idx];
	if (idx > start) {
		long long left = get_max_area(tree, v, start, idx - 1);
		area = max(area, left);
	}
	if (idx < end) {
		long long right = get_max_area(tree, v, idx + 1, end);
		area = max(area, right);
	}
	return area;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	while (n != 0) {
		vector<long long> v(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}

		int height = (int)ceil(log2(n));
		int tree_size = (1 << (height + 1));
		vector<long long> tree(tree_size);
		init(tree, v, 1, 1, n);
		cout << get_max_area(tree, v, 1, n) << "\n";
		cin >> n;
	}
}