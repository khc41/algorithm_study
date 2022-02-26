#include <iostream>
#include <vector>
using namespace std;

#define MAX 4000001 
bool p[MAX];
vector<int> prime;

void get_prime() {
	for (int i = 2; i < MAX; i++) {
		if (p[i] == true) continue;
		for (int j = 2 * i; j < MAX; j += i) {
			p[j] = true;
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (!p[i]) prime.push_back(i);
	}
}

int main() {
	int n, ans = 0;
	cin >> n;
	get_prime();
	int s = 0; int e = 0;
	int sum = 0; 
	int size = prime.size();
	while (s <= e) {
		if (sum >= n) {
			if (sum == n)
				ans++;
			sum -= prime[s++];
		}
		else if (e == size) break;
		else
			sum += prime[e++];
	}
	cout << ans;
}