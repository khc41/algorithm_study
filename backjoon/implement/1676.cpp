#include <iostream>

using namespace std;

int main() {
	int n, i, num, ans = 0;
	cin >> n;
	for (i = 1; i <= n; i++) {
		if (i % 5 == 0){
			num = i;
			while (num % 5 == 0 && num > 0) {
				num /= 5;
				ans++;
			}
		}
	}
	cout << ans;
}