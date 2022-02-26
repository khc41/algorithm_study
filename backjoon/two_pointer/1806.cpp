#include <iostream>

using namespace std;

#define MAX 100000001

int N, S;
int num[100001];

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int s = 0, e = 0;
	int mini = MAX;
	int sum = 0;
	while (s <= e) {
		if (sum >= S) {
			mini = min(mini, e - s);
			sum -= num[s++];
		}
		else if (e == N) break;
		else sum += num[e++];
	}
	if (mini == MAX)
		cout << "0";
	else
		cout << mini;
}