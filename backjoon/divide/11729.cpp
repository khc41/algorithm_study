#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int mid, int to) {
	if (n == 1) {
		cout << start << " " << to << "\n";
	}
	else {
		hanoi(n - 1, start, to, mid);
		cout << start << " " << to << "\n";
		hanoi(n - 1, mid, start, to);
	}
}

int main() {
	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << "\n";
	hanoi(n, 1, 2, 3);
}