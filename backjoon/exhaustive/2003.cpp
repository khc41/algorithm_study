#include <iostream>

using namespace std;

int n, m;
int num[10001];
int ans = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n ; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += num[j];
			if (sum == m) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
}