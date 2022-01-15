#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
	int n, i, j, in;
	cin >> n;
	int num[10001] = { 0, };
	for (i = 0; i < n; i++) {
		cin >> in;
		num[in] += 1;
	}
	for (i = 1; i <= 10000; i++) {
		for (j = 0; j < num[i]; j++) {
			printf("%d\n", i);
		}
	}	
}