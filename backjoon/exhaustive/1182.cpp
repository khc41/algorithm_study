#include <iostream>	

using namespace std;

long long num[21];
long long ans[21];
int n, s;
long long ret = 0;

void calSum(int idx, int pick, int depth) {
	ans[depth] = num[idx];
	if (pick == depth) {
		int sum = 0;
		for (int i = 0; i < depth + 1; i++) {
			sum += ans[i];
		}
		if (sum == s){
			ret++;
		}
		return;
	}
	for (int i = idx + 1; i < n; i++) {
		calSum(i, pick, depth + 1);
	}
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++) {
		for(int j =0; j < n; j++)
			calSum(j, i, 0);
	}
	cout << ret;
}