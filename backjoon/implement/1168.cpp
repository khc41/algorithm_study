#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int tree[(1<<18)];
int init(int node, int start, int end) {
	if (start == end) return tree[node] = 1;
	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);	
}

int update(int node, int start, int end, int index) {
	tree[node]--;
	if (start == end) return 0;
	int mid = (start + end) / 2;
	if(index <= mid) return update(node * 2, start, mid, index);
	else return update(node * 2 + 1, mid + 1, end, index);
}

int query(int node, int start, int end, int index) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (index <= tree[node * 2]) return query(node * 2, start, mid, index);
	else return query(node * 2 + 1, mid + 1, end, index - tree[node * 2]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i, n, k, index;
	cin >> n >> k;
	init(1, 1, n);
	index = 1;
	cout << "<";
	for (i = 0; i < n; i++) {
		int size = n - i;
		index += k - 1;
		if (index % size == 0) index = size;
		else if (index > size) index %= size;
		int num = query(1, 1, n, index);
		update(1, 1, n, num);
			if (i == n - 1) cout << num;
		else cout << num << ", ";
	}
	cout << ">";
}