#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int i, j, n, a = 0, b = 0;
	int* num = new int[1000001];
	for (int i = 2; i <= 1000000; i++) {
		num[i] = 1;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (num[i] == 0) continue;
		for (j = 2 * i; j <= 1000000; j += i) {
			num[j] = 0;
		}
	}

	cin >> n;
	while (n != 0) {
		int wrong = true;
		for (j = 3; j <= n; j++) {
			if (num[j] == 1 && num[n - j] == 1) {
				b = n - j;
				a = j;
				wrong = false;
				break;
			}
		}
		if (wrong) {
			printf("Goldbach's conjecture is wrong.\n");
		}
		else {
			printf("%d = %d + %d\n", n, a, b);
		}
		cin >> n;
	}
}