#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* list = new int[n];
	for (int i = 0; i < n; i++)
		cin >> list[i];
	sort(list, list+ n);
	cout << list[0] << " " << list[n - 1];
}
