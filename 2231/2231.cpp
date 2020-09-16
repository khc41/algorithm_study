#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int i, num, cnt, tmp, sum;
	cin >> num;
	cnt = 1; tmp = num;
	while (tmp > 10) {
		tmp /= 10;
		cnt++;
	}
	
	for (i = num - (9 * cnt); i < num; i++) {
		tmp = i;
		sum = i;
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == num) {
			cout << i;
			break;
		}
	}
	if (i == num)
		cout << 0;
}