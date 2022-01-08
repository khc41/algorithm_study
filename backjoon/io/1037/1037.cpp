#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, result;
	cin >> n;
	int* input = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);

	if (n % 2 == 0) {
		result = input[0] * input[n - 1];
	}
	else {
		result = input[n / 2 ] * input[n / 2 ];
	}
	
	cout << result;
}