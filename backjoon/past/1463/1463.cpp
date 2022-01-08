#include <iostream>
#include <vector>
using namespace std;

int main() {
	int i, j,n;
	cin >> n;
	vector<int> list(n+1, 999999);
	list[n] = 0;
	for (i = n; i > 0; i--) {
		if (i % 3 == 0) {
			if (list[i / 3] > list[i] + 1)
				list[i / 3] = list[i] + 1;
		}
		if (i % 2 == 0) {
			if (list[i/ 2] > list[i] + 1)
				list[i / 2] = list[i] + 1;
		}
		if (list[i - 1] > list[i] + 1)
			list[i-1]= list[i] +1;
		for (j = 0; j < n; j++)
			cout << list[j] << " ";
		cout << endl;
	}
	cout << list[1];
}