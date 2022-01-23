#include <iostream>
#include <cmath>
#include <memory.h>
#include <vector>
int map[240000];
using namespace std;

int main() {
	int a, p, i, rep;
	vector<int> v;
	cin >> a >> p;
	memset(map, 0, 240000 * sizeof(int));
	int num = a;
	map[num] = 1;
	v.push_back(a);
	while (1) {
		int sum = 0;
		while (num / 10 > 0) {
			sum += pow(num % 10, p);
			num /= 10;
		}
		sum += pow(num % 10, p);
		if (map[sum] == 0) {
			map[sum] = 1;
			v.push_back(sum);
			num = sum;
		}
		else {
			rep = sum;
			break;
		}
	}
	int sum = 0;
	for (i = 0; i < v.size(); i++) {
		if (v[i] != rep) sum++;
		else break;
	}
	cout << sum;
	
}