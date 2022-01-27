#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct node {
	int left = 0;
	int right = 0;
	int lm = 0;
	int rm = 0;
	int sum = 0;
};

vector<node> map(10001);

void inorder(int v) {
	if (map[v].left != 0) inorder(map[v].left);
	if (map[v].right != 0) inorder(map[v].right);
	map[v].lm += max(map[map[v].left].lm, map[map[v].left].rm);
	map[v].rm += max(map[map[v].right].lm, map[map[v].right].rm);
	map[v].sum = map[v].lm + map[v].rm;
	printf("%d %d %d %d \n", v, map[v].lm, map[v].rm, map[v].sum);
}

int main() {
	int n, i, p, c, w;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> p >> c >> w;
		if (map[p].left == 0) {
			map[p].left = c;
			map[p].lm = w;
		}
		else {
			map[p].right = c;
			map[p].rm = w;
		}
	}
	inorder(1);
	int res = -1;
	for (i = 1; i <= n; i++) {
		res = max(res, map[i].sum);
	}
	cout << res;

}