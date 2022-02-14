#include <iostream>
#include <algorithm>
using namespace std;

int h[1001];

int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	sort(h, h + n);
	for (int i = 0; i < n; i++)
		sum += (h[i] * (n - i));
	cout << sum;
}