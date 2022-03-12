#include <iostream>

using namespace std;

int n;
int a[12];
int oper[4];
int ans[2];

void calculate(int &value, int num, int idx) {
	if (idx == 0) value += num;
	else if (idx == 1) value -= num;
	else if (idx == 2) value *= num;
	else if (idx == 3) value /= num;
}

void dfs(int num, int depth) {
	if (depth == n) {
		ans[0] = max(ans[0], num);
		ans[1] = min(ans[1], num);
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] != 0) {
			oper[i]--;
			int cp = num;
			calculate(num, a[depth], i);
			dfs(num, depth + 1);
			num = cp;
			oper[i]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	ans[0] = -10000000001;
	ans[1] = 10000000001;
	dfs(a[0], 1);
	for (int i = 0; i < 2; i++)
		cout << ans[i] << "\n";
}