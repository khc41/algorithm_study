#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, i;
	cin >> n;
	int* in = new int[n];
	for (i = 0; i < n; i++) cin >> in[i];
	sort(in, in + n);
	for (i = 0; i < n; i++) printf("%d\n", in[i]);
}